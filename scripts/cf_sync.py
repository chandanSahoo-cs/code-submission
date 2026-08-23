#!/usr/bin/env python3
"""
Interactive Codeforces Sync with Playwright + backdated Git history.

Features:
1. Opens browser and lets you log in.
2. Saves the browser session for future runs.
3. Traverses Codeforces submission pages.
4. Finds accepted submissions.
5. Constructs both the problem URL and the submission URL directly
   from their components (contest/gym id + problem index), instead
   of depending on the scraped href as a fallback.
6. Downloads the exact submitted code.
7. Downloads the problem statement.
8. Commits each problem individually to git.
9. Uses the actual Codeforces judged/submission time as the git commit date.
10. Optionally pushes to GitHub.
"""

import os
import re
import sys
import time
import random
import logging
import argparse
import subprocess

from pathlib import Path
from datetime import datetime
from zoneinfo import ZoneInfo

from bs4 import BeautifulSoup
from playwright.sync_api import sync_playwright

# ============================================================
# Math / Markdown formatting
# ============================================================

SUP_MAP = {
    "0": "⁰",
    "1": "¹",
    "2": "²",
    "3": "³",
    "4": "⁴",
    "5": "⁵",
    "6": "⁶",
    "7": "⁷",
    "8": "⁸",
    "9": "⁹",
    "+": "⁺",
    "-": "⁻",
    "n": "ⁿ",
    "k": "ᵏ",
    "m": "ᵐ",
    "i": "ⁱ",
}

SUB_MAP = {
    "0": "₀",
    "1": "₁",
    "2": "₂",
    "3": "₃",
    "4": "₄",
    "5": "₅",
    "6": "₆",
    "7": "₇",
    "8": "₈",
    "9": "₉",
    "i": "ᵢ",
    "j": "ⱼ",
    "n": "ₙ",
    "k": "ₖ",
    "m": "ₘ",
    "a": "ₐ",
    "x": "ₓ",
}


def format_math_expr(expr: str) -> str:
    expr = re.sub(r"\\color\{[^}]+\}\{([^}]+)\}", r"\1", expr)
    expr = re.sub(r"\\frac\{([^}]+)\}\{([^}]+)\}", r"(\1/\2)", expr)
    expr = (
        expr.replace("\\le", "≤")
        .replace("\\leq", "≤")
        .replace("\\ge", "≥")
        .replace("\\geq", "≥")
        .replace("\\ne", "≠")
        .replace("\\neq", "≠")
        .replace("\\cdot", " · ")
        .replace("\\times", " × ")
        .replace("\\dots", "…")
        .replace("\\ldots", "…")
        .replace("\\min", "min")
        .replace("\\max", "max")
        .replace("\\oplus", "⊕")
        .replace("\\sum", "∑")
        .replace("\\in", "∈")
        .replace("\\infty", "∞")
        .replace("\\sqrt", "√")
    )
    expr = re.sub(
        r"([a-zA-Z0-9]+)\^\{?([0-9a-z+-]+)\}?",
        lambda m: (f"{m.group(1)}" f"{''.join(SUP_MAP.get(c, c) for c in m.group(2))}"),
        expr,
    )
    expr = re.sub(
        r"([a-zA-Z])_\{?([0-9a-z])\}?",
        lambda m: (
            f"{m.group(1)}" f"{''.join(SUB_MAP.get(c, f'_{c}') for c in m.group(2))}"
        ),
        expr,
    )
    return re.sub(r"\s+", " ", expr.replace("\\", "")).strip()


def clean_problem_text(text: str) -> str:
    if not text:
        return ""
    text = re.sub(r"\$\$\$(.*?)\$\$\$", lambda m: format_math_expr(m.group(1)), text)
    text = re.sub(r"\$\$(.*?)\$\$", lambda m: format_math_expr(m.group(1)), text)
    text = re.sub(r"\$([^$\n]+)\$", lambda m: format_math_expr(m.group(1)), text)
    return text.replace("$$$", "").replace("$$", "")


def sanitize_filename(name: str) -> str:
    name = re.sub(r'[\\/*?:"<>|]', "", name)
    name = re.sub(r"\s+", " ", name)
    return name.strip()[:100]


# ============================================================
# Constants
# ============================================================

META_FILENAME = ".sync_meta"


# ------------------------------------------------------------
# Minimum submission ID.
#
# Only submissions with an ID STRICTLY GREATER THAN this value
# are processed. Everything at or below it is skipped.
# ------------------------------------------------------------

MIN_SUBMISSION_ID = 387938753


def is_below_min_submission_id(submission_id: int) -> bool:
    return submission_id <= MIN_SUBMISSION_ID


# ============================================================
# ICPC Assiut University Community exclusions
# ============================================================

EXCLUDED_GROUP_CONTEST_IDS = {
    "219158",  # Sheet #1
    "219432",  # Sheet #2
    "219774",  # Sheet #3
    "219856",  # Sheet #4
    "223205",  # Sheet #5
    "223338",  # Sheet #6
    "223339",  # Sheet #7
    "223206",  # Sheet #8
    "223207",  # Sheet #9
    "223340",  # Sheet #10
    "326175",  # Contest #1
    "326907",  # Contest #2
    "329103",  # Contest #3.1
}


# ============================================================
# Submission timestamp parsing
# ============================================================

DATETIME_RE = re.compile(r"(\d{4}-\d{2}-\d{2})[\s\u00a0]+" r"(\d{2}:\d{2}:\d{2})")


def extract_row_datetime(row, tz: ZoneInfo, logger=None, prob_name: str = ""):
    """
    Extract the Judged timestamp from a submissions-table row.

    Codeforces generally has:

        Sent
        Judged

    with Judged being the later timestamp.

    Therefore we use the last timestamp found in the row.
    """
    text = row.get_text(separator=" ", strip=True).replace("\xa0", " ")
    matches = DATETIME_RE.findall(text)
    if not matches:
        if logger:
            logger.debug(
                f"    [debug] No timestamp found for "
                f"{prob_name!r}. Row text: {text!r}"
            )
        return None
    date_str, time_str = matches[-1]
    try:
        naive = datetime.strptime(f"{date_str} {time_str}", "%Y-%m-%d %H:%M:%S")
        return naive.replace(tzinfo=tz)
    except ValueError:
        if logger:
            logger.debug(
                f"    [debug] Timestamp parsing failed for "
                f"{prob_name!r}: {date_str} {time_str}"
            )
        return None


def extract_submission_datetime_from_page(
    page, tz: ZoneInfo, logger=None, prob_name: str = ""
):
    """
    Extract the Judged timestamp from an individual submission page.

    Example:

    https://codeforces.com/contest/1692/submission/387938753
    """
    soup = BeautifulSoup(page.content(), "html.parser")
    irt_div = soup.find("div", class_="irt")
    table = irt_div.find_next("table") if irt_div else None
    if table is None:
        for t in soup.find_all("table"):
            header_text = t.get_text(" ", strip=True)
            if "Judged" in header_text and "Sent" in header_text:
                table = t
                break
    if table is None:
        if logger:
            logger.debug(
                f"    [debug] No submission-info table " f"found for {prob_name!r}."
            )
        return None
    rows = table.find_all("tr")
    if len(rows) < 2:
        if logger:
            logger.debug(
                f"    [debug] Submission-info table for "
                f"{prob_name!r} had only {len(rows)} row(s)."
            )
        return None
    data_row = rows[1]
    cells = data_row.find_all("td")
    if len(cells) < 9:
        if logger:
            logger.debug(
                f"    [debug] Submission-info row for "
                f"{prob_name!r} had only {len(cells)} cells."
            )
        return None
    judged_text = cells[8].get_text(separator=" ", strip=True).replace("\xa0", " ")
    match = DATETIME_RE.search(judged_text)
    if not match:
        if logger:
            logger.debug(
                f"    [debug] Judged cell for "
                f"{prob_name!r} didn't match timestamp: "
                f"{judged_text!r}"
            )
        return None
    date_str, time_str = match.groups()
    try:
        naive = datetime.strptime(f"{date_str} {time_str}", "%Y-%m-%d %H:%M:%S")
        return naive.replace(tzinfo=tz)
    except ValueError:
        if logger:
            logger.debug(
                f"    [debug] Could not parse judged " f"timestamp for {prob_name!r}"
            )
        return None


# ============================================================
# Metadata helpers
# ============================================================


def read_saved_submission_id(prob_dir: Path):
    """
    Return the submission ID previously saved for this problem.
    """
    meta_path = prob_dir / META_FILENAME
    if not meta_path.exists():
        return None
    try:
        return int(meta_path.read_text(encoding="utf-8").strip())
    except (ValueError, OSError):
        return None


def write_saved_submission_id(prob_dir: Path, sub_id: str):
    (prob_dir / META_FILENAME).write_text(str(sub_id), encoding="utf-8")


# ============================================================
# Logging
# ============================================================


def setup_logging(log_file: str, debug: bool = False):
    logger = logging.getLogger("cf_sync")
    logger.setLevel(logging.DEBUG if debug else logging.INFO)
    logger.handlers.clear()
    fmt = logging.Formatter("%(asctime)s %(message)s", datefmt="%Y-%m-%d %H:%M:%S")
    console = logging.StreamHandler(sys.stdout)
    console.setLevel(logging.DEBUG if debug else logging.INFO)
    console.setFormatter(fmt)
    logger.addHandler(console)
    file_handler = logging.FileHandler(log_file, encoding="utf-8")
    file_handler.setLevel(logging.DEBUG if debug else logging.INFO)
    file_handler.setFormatter(fmt)
    logger.addHandler(file_handler)
    return logger


# ============================================================
# Navigation
# ============================================================


def safe_goto(
    page,
    url,
    wait_selector=None,
    wait_timeout=15000,
    retries=3,
    retry_delay=15,
    logger=None,
    description="",
):
    """
    Navigate to a URL with retries.
    """
    label = description or url
    for attempt in range(1, retries + 1):
        try:
            page.goto(url, timeout=60000)
            if wait_selector:
                page.wait_for_selector(wait_selector, timeout=wait_timeout)
            return True
        except Exception as e:
            if logger:
                logger.info(
                    f"    [!] Attempt "
                    f"{attempt}/{retries} failed for "
                    f"{label}: {e}"
                )
            if attempt < retries:
                time.sleep(retry_delay)
    if logger:
        logger.info(f"    [!] Giving up on {label} " f"after {retries} attempts.")
    return False


# ============================================================
# Login
# ============================================================


def check_logged_in(page) -> bool:
    """
    Check whether the current Codeforces session is authenticated.
    """
    soup = BeautifulSoup(page.content(), "html.parser")
    logout_link = soup.find("a", href=re.compile(r"^/logout"))
    enter_link = soup.find("a", href=re.compile(r"^/enter"))
    return bool(logout_link) and not bool(enter_link)


# ============================================================
# URL construction
#
# Both the problem URL and the submission URL are always built
# directly from their components (contest/gym id + problem
# index), rather than depending on the raw scraped href as a
# fallback.
# ============================================================


def build_problem_url(prob_href: str):
    """
    Construct the Codeforces problem URL DIRECTLY from its
    contest/gym id and problem index, instead of just
    prepending the domain to whatever href was scraped.

    Examples:

        /contest/1692/problem/A
        ->
        https://codeforces.com/contest/1692/problem/A

        /gym/123456/problem/A
        ->
        https://codeforces.com/gym/123456/problem/A

        /problemset/problem/1692/A
        ->
        https://codeforces.com/problemset/problem/1692/A

    Returns:
        prob_url, contest_id
    """
    match = re.search(r"/contest/(\d+)/problem/([^/?#]+)", prob_href)
    if match:
        contest_id, letter = match.groups()
        url = "https://codeforces.com/" f"contest/{contest_id}/" f"problem/{letter}"
        return url, contest_id
    match = re.search(r"/gym/(\d+)/problem/([^/?#]+)", prob_href)
    if match:
        gym_id, letter = match.groups()
        url = "https://codeforces.com/" f"gym/{gym_id}/" f"problem/{letter}"
        return url, gym_id
    match = re.search(r"/problemset/problem/(\d+)/([^/?#]+)", prob_href)
    if match:
        contest_id, letter = match.groups()
        url = "https://codeforces.com/" f"problemset/problem/" f"{contest_id}/{letter}"
        return url, contest_id
    return None, None


def build_submission_url(prob_href: str, submission_id: int):
    """
    Construct the Codeforces submission URL DIRECTLY.

    We deliberately DO NOT search the submission row for an
    <a href="/submission/..."> anchor.

    Examples:

        /contest/1692/problem/A
        ->
        https://codeforces.com/contest/1692/submission/387938753

        /gym/123456/problem/A
        ->
        https://codeforces.com/gym/123456/submission/387938753

        /problemset/problem/1692/A
        ->
        https://codeforces.com/problemset/submission/1692/387938753

    Returns:
        submission_url, contest_id, source_type
    """
    # --------------------------------------------------------
    # Normal contest
    # --------------------------------------------------------
    match = re.search(r"/contest/(\d+)/problem/", prob_href)
    if match:
        contest_id = match.group(1)
        url = (
            "https://codeforces.com/"
            f"contest/{contest_id}/"
            f"submission/{submission_id}"
        )
        return url, contest_id, "contest"
    # --------------------------------------------------------
    # Gym
    # --------------------------------------------------------
    match = re.search(r"/gym/(\d+)/problem/", prob_href)
    if match:
        gym_id = match.group(1)
        url = "https://codeforces.com/" f"gym/{gym_id}/" f"submission/{submission_id}"
        return url, gym_id, "gym"
    # --------------------------------------------------------
    # Problemset
    # --------------------------------------------------------
    match = re.search(r"/problemset/problem/(\d+)/", prob_href)
    if match:
        contest_id = match.group(1)
        url = (
            "https://codeforces.com/"
            f"problemset/submission/"
            f"{contest_id}/{submission_id}"
        )
        return url, contest_id, "problemset"
    # --------------------------------------------------------
    # Could not determine URL
    # --------------------------------------------------------
    return None, None, None


# ============================================================
# Git helpers
# ============================================================


def is_git_repo(repo_dir: Path) -> bool:
    return (repo_dir / ".git").is_dir()


def git_commit_backdated(
    repo_dir: Path,
    rel_paths,
    message: str,
    commit_dt: datetime,
    author_name: str = None,
    author_email: str = None,
) -> bool:
    """
    Commit only the supplied paths.

    Both author and committer dates are backdated.
    """
    date_str = commit_dt.strftime("%Y-%m-%d %H:%M:%S %z")
    subprocess.run(
        ["git", "add"] + [str(p) for p in rel_paths], cwd=repo_dir, check=True
    )
    status = subprocess.run(
        ["git", "status", "--porcelain"] + [str(p) for p in rel_paths],
        cwd=repo_dir,
        capture_output=True,
        text=True,
        check=True,
    )
    if not status.stdout.strip():
        return False
    env = os.environ.copy()
    env["GIT_AUTHOR_DATE"] = date_str
    env["GIT_COMMITTER_DATE"] = date_str
    if author_name:
        env["GIT_AUTHOR_NAME"] = author_name
        env["GIT_COMMITTER_NAME"] = author_name
    if author_email:
        env["GIT_AUTHOR_EMAIL"] = author_email
        env["GIT_COMMITTER_EMAIL"] = author_email
    subprocess.run(["git", "commit", "-m", message], cwd=repo_dir, check=True, env=env)
    return True


def git_push(repo_dir: Path):

    print("[*] Git: Pushing changes to remote...")
    try:
        subprocess.run(["git", "push"], cwd=repo_dir, check=True)
        print("[+] Git: Push successful!")
    except subprocess.CalledProcessError as e:
        print(f"[!] Git push failed: {e}")


# ============================================================
# Main
# ============================================================


def main():

    parser = argparse.ArgumentParser(description="Codeforces Interactive Sync")
    parser.add_argument(
        "--user", "-u", type=str, default="Realmchan", help="Codeforces username"
    )
    parser.add_argument(
        "--limit",
        "-l",
        type=int,
        default=None,
        help="Limit number of problems to download",
    )
    parser.add_argument(
        "--pages", type=int, default=40, help="Maximum submission pages to search"
    )
    parser.add_argument(
        "--dir",
        "-d",
        type=str,
        default=".",
        help="Target directory. Must be a git clone.",
    )
    parser.add_argument(
        "--push", "-p", action="store_true", help="Push to git remote after committing"
    )
    parser.add_argument(
        "--force", "-f", action="store_true", help="Force re-download existing problems"
    )
    parser.add_argument(
        "--tz",
        type=str,
        default="Asia/Kolkata",
        help=(
            "Timezone your Codeforces account displays times in "
            "(default: Asia/Kolkata)"
        ),
    )
    parser.add_argument(
        "--author-name",
        type=str,
        default=None,
        help="Override git author/committer name",
    )
    parser.add_argument(
        "--author-email",
        type=str,
        default=None,
        help="Override git author/committer email",
    )
    parser.add_argument(
        "--headless",
        action="store_true",
        help=(
            "Run without a visible browser window. "
            "Requires an existing saved login session."
        ),
    )
    parser.add_argument(
        "--min-delay",
        type=float,
        default=1.0,
        help="Minimum seconds to wait between problems",
    )
    parser.add_argument(
        "--max-delay",
        type=float,
        default=2.5,
        help="Maximum seconds to wait between problems",
    )
    parser.add_argument("--retries", type=int, default=3, help="Retries per page load")
    parser.add_argument(
        "--retry-delay",
        type=float,
        default=15.0,
        help="Seconds to wait between retries",
    )
    parser.add_argument(
        "--push-every",
        type=int,
        default=None,
        help=("Push after every N commits instead of only at the end"),
    )
    parser.add_argument("--log-file", type=str, default="cf_sync.log", help="Log file")
    parser.add_argument(
        "--exclude-contest-id",
        action="append",
        default=None,
        help=(
            "Extra Codeforces contest IDs to exclude. "
            "Can be supplied multiple times."
        ),
    )
    parser.add_argument(
        "--min-submission-id",
        type=int,
        default=MIN_SUBMISSION_ID,
        help=(
            "Only process submissions with an ID strictly greater "
            f"than this value (default: {MIN_SUBMISSION_ID})"
        ),
    )
    parser.add_argument("--debug", action="store_true", help="Enable debug logging")
    args = parser.parse_args()
    handle = args.user
    repo_dir = Path(args.dir).resolve()
    output_dir = repo_dir / "codeforces"
    output_dir.mkdir(parents=True, exist_ok=True)
    tz = ZoneInfo(args.tz)
    log = setup_logging(args.log_file, debug=args.debug)
    # ========================================================
    # Git validation
    # ========================================================
    git_enabled = is_git_repo(repo_dir)
    if not git_enabled:
        log.info(f"[!] {repo_dir} is not a git repository " f"(no .git folder found).")
        log.info(
            "    Files will still be downloaded, " "but NOTHING will be committed."
        )
        log.info("    Clone your repo using git clone.")
        if args.push:
            log.info("[!] --push ignored because this isn't a git repo.")
    # ========================================================
    # Login session
    # ========================================================
    session_dir = Path("./cf_session").resolve()
    with sync_playwright() as p:
        log.info(
            f"[*] Starting browser session "
            f"(stored in {session_dir.name}, "
            f"headless={args.headless})..."
        )
        context = p.chromium.launch_persistent_context(
            user_data_dir=str(session_dir),
            headless=args.headless,
            args=["--disable-blink-features=AutomationControlled"],
        )
        page = context.new_page()
        # ====================================================
        # Step 1: Login
        # ====================================================
        log.info("[*] Opening Codeforces...")
        page.goto("https://codeforces.com/", timeout=60000)
        page.wait_for_load_state("networkidle")
        is_logged_in = check_logged_in(page)
        if not is_logged_in and args.headless:
            log.info("[!] Not logged in and --headless was passed.")
            log.info("    Run once WITHOUT --headless first.")
            context.close()
            sys.exit(1)
        if not is_logged_in:
            print("\n" + "=" * 60)
            print(">>> PLEASE LOG IN TO CODEFORCES " "IN THE OPENED BROWSER <<<")
            print("=" * 60)
            input("Press [ENTER] after logging in...")
            page.reload()
            page.wait_for_load_state("networkidle")
            log.info("[+] Continuing...\n")
        else:
            log.info("[+] Already logged in!")
        # ====================================================
        # Contest exclusions
        # ====================================================
        excluded_contest_ids = set(EXCLUDED_GROUP_CONTEST_IDS)
        if args.exclude_contest_id:
            excluded_contest_ids.update(args.exclude_contest_id)
        log.info(f"[+] Excluding " f"{len(excluded_contest_ids)} contest ID(s).")
        log.info(
            f"[+] Only processing submissions with ID "
            f"greater than {args.min_submission_id}.\n"
        )
        # ====================================================
        # Step 2: Scrape submissions
        # ====================================================
        log.info(f"[*] Scraping accepted submissions " f"for {handle}...")
        tasks_by_prob = {}
        skipped_group_count = 0
        skipped_below_min_count = 0
        for page_num in range(1, args.pages + 1):
            sub_list_url = (
                f"https://codeforces.com/" f"submissions/{handle}/" f"page/{page_num}"
            )
            log.info(f"    -> Loading submissions page " f"{page_num}...")
            ok = safe_goto(
                page,
                sub_list_url,
                wait_selector="tr[data-submission-id]",
                wait_timeout=10000,
                retries=args.retries,
                retry_delay=args.retry_delay,
                logger=log,
                description=(f"submissions page {page_num}"),
            )
            if not ok:
                log.info(f"    [!] Stopping pagination at " f"page {page_num}.")
                break
            soup = BeautifulSoup(page.content(), "html.parser")
            rows = soup.find_all("tr", attrs={"data-submission-id": True})
            if not rows:
                break
            # =================================================
            # Since Codeforces lists submissions in descending
            # ID order, once every submission on a page is at or
            # below the minimum submission ID, every following
            # page will be too. Stop paginating right here.
            # =================================================
            page_sub_ids = []
            for row in rows:
                try:
                    page_sub_ids.append(int(row.get("data-submission-id")))
                except (TypeError, ValueError):
                    pass
            if page_sub_ids and max(page_sub_ids) <= args.min_submission_id:
                log.info(
                    f"    [i] All submissions on page {page_num} are at "
                    f"or below the minimum submission ID "
                    f"({args.min_submission_id}); stopping pagination."
                )
                break
            for row in rows:
                # =================================================
                # Check verdict
                # =================================================
                verdict_wrapper = row.find("span", class_="submissionVerdictWrapper")
                is_ac = False
                if verdict_wrapper and verdict_wrapper.get("submissionverdict") == "OK":
                    is_ac = True
                elif (
                    row.find("span", class_="verdict-accepted")
                    or "Accepted" in row.get_text()
                ):
                    is_ac = True
                if not is_ac:
                    continue
                # =================================================
                # Problem URL
                # =================================================
                prob_link = row.find("a", href=re.compile(r"/problem/"))
                if not prob_link:
                    continue
                prob_href = prob_link.get("href", "")
                prob_name = prob_link.get_text().strip()
                # =================================================
                # Submission ID
                # =================================================
                sub_id_raw = row.get("data-submission-id")
                try:
                    sub_id = int(sub_id_raw)
                except (TypeError, ValueError):
                    continue
                # =================================================
                # MINIMUM SUBMISSION ID FILTER
                #
                # Only submissions strictly greater than this ID
                # are considered at all.
                # =================================================
                if sub_id <= args.min_submission_id:
                    skipped_below_min_count += 1
                    log.debug(
                        f"    [debug] Skipping submission "
                        f"{sub_id} (<= min "
                        f"{args.min_submission_id}): "
                        f"{prob_name}"
                    )
                    continue
                # =================================================
                # Build problem URL directly from its components
                # (contest/gym id + problem index), instead of
                # falling back to the scraped href as-is.
                # =================================================
                prob_url, contest_id = build_problem_url(prob_href)
                if prob_url is None:
                    log.debug(
                        f"    [debug] Could not construct "
                        f"problem URL for {prob_name!r}. "
                        f"Problem href: {prob_href!r}"
                    )
                    continue
                # =================================================
                # Contest exclusion
                # =================================================
                if contest_id and contest_id in excluded_contest_ids:
                    skipped_group_count += 1
                    continue
                # =================================================
                # IMPORTANT:
                #
                # We DO NOT search for an anchor to the submission.
                #
                # The URL is always constructed directly from:
                #
                #     problem href
                #     +
                #     submission ID
                #
                # Example:
                #
                # /contest/1692/problem/A
                #
                # +
                #
                # 387938753
                #
                # =
                #
                # https://codeforces.com/
                # contest/1692/submission/387938753
                # =================================================
                sub_url, detected_id, source_type = build_submission_url(
                    prob_href, sub_id
                )
                if sub_url is None:
                    log.debug(
                        f"    [debug] Could not construct "
                        f"submission URL for "
                        f"{prob_name!r}. "
                        f"Problem href: {prob_href!r}"
                    )
                    continue
                # =================================================
                # Submission timestamp from row
                # =================================================
                row_dt = extract_row_datetime(row, tz, logger=log, prob_name=prob_name)
                # =================================================
                # Keep latest accepted submission per problem
                # =================================================
                existing = tasks_by_prob.get(prob_url)
                if existing is None or sub_id > existing["sub_id"]:
                    tasks_by_prob[prob_url] = {
                        "sub_id": sub_id,
                        "sub_url": sub_url,
                        "prob_url": prob_url,
                        "prob_name": prob_name,
                        "commit_dt": row_dt,
                    }
                if args.limit and len(tasks_by_prob) >= args.limit:
                    break
            if args.limit and len(tasks_by_prob) >= args.limit:
                break
        # ========================================================
        # Sort by submission ID
        # ========================================================
        tasks = sorted(tasks_by_prob.values(), key=lambda t: t["sub_id"])
        log.info("\n[+] Total unique accepted problems found: " f"{len(tasks)}\n")
        if skipped_below_min_count:
            log.info(
                f"[i] Skipped "
                f"{skipped_below_min_count} "
                f"submission(s) at or below the minimum "
                f"submission ID ({args.min_submission_id})."
            )
        if skipped_group_count:
            log.info(
                f"[i] Skipped "
                f"{skipped_group_count} "
                f"submission(s) belonging to excluded "
                f"contest groups."
            )
        # ========================================================
        # Step 3: Download + commit
        # ========================================================
        saved_count = 0
        committed_count = 0
        failed = []
        for i, item in enumerate(tasks, 1):
            name = item["prob_name"]
            sub_url = item["sub_url"]
            prob_url = item["prob_url"]
            folder_name = sanitize_filename(name)
            prob_dir = output_dir / folder_name
            sol_path = prob_dir / "solution.cpp"
            readme_path = prob_dir / "README.md"
            current_sub_id = item["sub_id"]
            # ====================================================
            # Existing metadata
            # ====================================================
            saved_sub_id = read_saved_submission_id(prob_dir)
            already_complete = sol_path.exists() and readme_path.exists()
            if (
                not args.force
                and already_complete
                and saved_sub_id is not None
                and saved_sub_id >= current_sub_id
            ):
                log.info(
                    f"[{i}/{len(tasks)}] "
                    f"[SKIPPED - Up to date, "
                    f"submission {saved_sub_id}] "
                    f"{name}"
                )
                continue
            prob_dir.mkdir(parents=True, exist_ok=True)
            if already_complete and (
                saved_sub_id is None or saved_sub_id < current_sub_id
            ):
                log.info(
                    f"[{i}/{len(tasks)}] "
                    f"Overwriting with newer submission "
                    f"({saved_sub_id} -> "
                    f"{current_sub_id}): "
                    f"{name}"
                )
            else:
                log.info(f"[{i}/{len(tasks)}] " f"Fetching: {name}")
            log.info(f"    [URL] {sub_url}")
            # ====================================================
            # Submission time
            # ====================================================
            commit_dt = item.get("commit_dt")
            # ====================================================
            # Fetch submission
            # ====================================================
            got_sub = safe_goto(
                page,
                sub_url,
                wait_selector="pre#program-source-text",
                wait_timeout=15000,
                retries=args.retries,
                retry_delay=args.retry_delay,
                logger=log,
                description=(f"submission page for {name}"),
            )
            if not got_sub:
                log.info(
                    f"    [!] Skipping {name} "
                    f"entirely — submission page "
                    f"unreachable after retries."
                )
                failed.append(name)
                time.sleep(random.uniform(args.min_delay, args.max_delay))
                continue
            # ====================================================
            # Get authoritative Judged time from submission page
            # ====================================================
            page_dt = extract_submission_datetime_from_page(
                page, tz, logger=log, prob_name=name
            )
            if page_dt is not None:
                commit_dt = page_dt
            elif commit_dt is None:
                log.info(
                    f"    [!] Warning: Could not read "
                    f"submission time for {name}. "
                    f"Commit will use current time."
                )
            # ====================================================
            # Extract source code
            # ====================================================
            try:
                sub_soup = BeautifulSoup(page.content(), "html.parser")
                pre = sub_soup.find("pre", id="program-source-text")
                if pre:
                    lis = pre.find_all("li")
                    if lis:
                        code = "\n".join(li.get_text() for li in lis)
                    else:
                        code = pre.get_text()
                    with open(sol_path, "w", encoding="utf-8") as f:
                        f.write(code)
                else:
                    log.info(f"    [!] Could not find " f"source code for {name}")
            except Exception as e:
                log.info(
                    f"    [!] Warning: Could not "
                    f"extract code from "
                    f"{sub_url}: {e}"
                )
            # ====================================================
            # Fetch problem statement
            # ====================================================
            got_prob = safe_goto(
                page,
                prob_url,
                wait_selector="div.problem-statement",
                wait_timeout=15000,
                retries=args.retries,
                retry_delay=args.retry_delay,
                logger=log,
                description=(f"problem statement for {name}"),
            )
            try:
                if not got_prob:
                    raise RuntimeError(
                        "problem statement page " "unreachable after retries"
                    )
                prob_soup = BeautifulSoup(page.content(), "html.parser")
                ps = prob_soup.find("div", class_="problem-statement")
                if ps:
                    # ============================================
                    # Title
                    # ============================================
                    title_el = ps.find("div", class_="title")
                    title = title_el.get_text().strip() if title_el else name
                    # ============================================
                    # Remove header
                    # ============================================
                    header = ps.find("div", class_="header")
                    if header:
                        header.decompose()
                    # ============================================
                    # Build README
                    # ============================================
                    statement = f"# [{title}]({prob_url})\n\n" "---\n"
                    for child in ps.children:
                        if not hasattr(child, "name") or not child.name:
                            continue
                        classes = child.get("class", [])
                        # ----------------------------------------
                        # Section title
                        # ----------------------------------------
                        if "section-title" in classes:
                            text = child.get_text().strip()
                            text = clean_problem_text(text)
                            statement += f"\n### {text}\n"
                        # ----------------------------------------
                        # Input
                        # ----------------------------------------
                        elif "input-specification" in classes:
                            text = child.get_text().strip()
                            text = clean_problem_text(text)
                            statement += f"\n### Input\n" f"{text}\n"
                        # ----------------------------------------
                        # Output
                        # ----------------------------------------
                        elif "output-specification" in classes:
                            text = child.get_text().strip()
                            text = clean_problem_text(text)
                            statement += f"\n### Output\n" f"{text}\n"
                        # ----------------------------------------
                        # Skip samples
                        # ----------------------------------------
                        elif "sample-tests" not in classes:
                            text = child.get_text().strip()
                            if text:
                                text = clean_problem_text(text)
                                statement += f"{text}\n"
                    with open(readme_path, "w", encoding="utf-8") as f:
                        f.write(statement)
                else:
                    log.info(f"    [!] Problem statement " f"not found for {name}")
            except Exception as e:
                log.info(
                    f"    [!] Warning: Could not "
                    f"extract statement from "
                    f"{prob_url}: {e}"
                )
            # ====================================================
            # Save metadata
            # ====================================================
            write_saved_submission_id(prob_dir, current_sub_id)
            log.info(f"    [OK] Saved to: " f"{prob_dir.name}")
            saved_count += 1
            # ====================================================
            # Git commit
            # ====================================================
            if git_enabled:
                if commit_dt is None:
                    commit_dt = datetime.now(tz=tz)
                rel_path = prob_dir.relative_to(repo_dir)
                message = f"[Codeforces Sync] {name}"
                try:
                    made_commit = git_commit_backdated(
                        repo_dir,
                        [rel_path],
                        message,
                        commit_dt,
                        author_name=args.author_name,
                        author_email=args.author_email,
                    )
                    if made_commit:
                        log.info(
                            f"    [GIT] Committed "
                            f"({commit_dt.strftime('%Y-%m-%d %H:%M %z')}): "
                            f"{message}"
                        )
                        committed_count += 1
                        if (
                            args.push
                            and args.push_every
                            and committed_count % args.push_every == 0
                        ):
                            git_push(repo_dir)
                    else:
                        log.info(f"    [GIT] No file changes " f"to commit for {name}")
                except subprocess.CalledProcessError as e:
                    log.info(f"    [!] Git commit failed " f"for {name}: {e}")
            # ====================================================
            # Delay
            # ====================================================
            time.sleep(random.uniform(args.min_delay, args.max_delay))
        # ========================================================
        # Close browser
        # ========================================================
        context.close()
    # ============================================================
    # Final summary
    # ============================================================
    log.info(f"\n[SUCCESS] Completed!")
    log.info(f"[SUCCESS] Saved {saved_count} " f"problems into: {output_dir}")
    if git_enabled:
        log.info(f"[SUCCESS] Made " f"{committed_count} " f"backdated commits.")
    if failed:
        log.info(
            f"[!] {len(failed)} "
            f"problem(s) failed after retries "
            f"and were skipped:"
        )
        for name in failed:
            log.info(f"    - {name}")
        log.info("    Re-run the same command to retry.")
    if args.push and git_enabled and committed_count > 0:
        git_push(repo_dir)


# ============================================================
# Entry point
# ============================================================

if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("\n[!] Interrupted. Exiting.")
        sys.exit(130)