# [A. Chess For Three](https://codeforces.com/contest/1973/problem/A)

---
Three friends gathered to play a few games of chess together.In every game, two of them play against each other. The winner gets 2 points while the loser gets 0, and in case of a draw, both players get 1 point each. Note that the same pair of players could have played any non-negative number of times (possibly zero). It is also possible that no games were played at all. You've been told that their scores after all the games were played were p1, p2 and p3. Additionally, it is guaranteed that p1≤p2≤p3 holds.Find the maximum number of draws that could have happened and print it. If there isn't any way to obtain p1, p2 and p3 as a result of a non-negative number of games between the three players, print −1 instead.

### Input
InputEach test contains multiple test cases. The first line contains the number of test cases t (1≤t≤500). The description of the test cases follows.The first line of each test case contains three integers p1, p2 and p3 (0≤p1≤p2≤p3≤30) — the scores of the three players, sorted non-decreasingly.

### Output
OutputFor each testcase, print one number — the maximum possible number of draws that could've happened, or −1 if the scores aren't consistent with any valid set of games and results.
NoteIn the first example, no games were played at all, so no draws could occur either.For the second example, exactly one game occurred between the second and the third player and it ended in draw, so the answer is 1.It's easy to see that there's no set of games achieving the scores in third example, so the answer for it is −1.
