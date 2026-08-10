# [B. Domino Tiles](https://codeforces.com/contest/2256/problem/B)

---
Nygglatho returns from the market with an old box of tiles whose painted marks have begun to fade. Before she can put it away, Chtholly and the young fairies have already spread the tiles across the dining table and turned them into a puzzle.There is a row of n tiles. Each tile should be marked with either 0 or 1. However, some of the marks have faded away.The current row is represented by a string s of length n. Each character of s is 0, 1, or ?. Chtholly must replace every ? with either 0 or 1.After replacement, for every 1≤i<n, the two neighboring tiles si and si+1 form a domino of weight (si+si+1). Note that two consecutive dominoes share exactly one tile. The completed row is valid if every two consecutive dominoes have different weights.Determine the number of different∗ ways to replace all ? characters so that the completed row is valid. Output the answer modulo 998244353.∗Two ways of replacement are considered different if the resulting strings are different.

### Input
InputEach test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows.The first line of each test case contains one integer n (2≤n≤2⋅105) — the number of tiles.The second line contains the string s of length n, where si=0, 1, or ?.It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

### Output
OutputFor each test case, output one integer — the number of valid ways to replace all ? characters, modulo 998244353.
NoteIn the first test case, there is only one domino, so every completion is valid. The valid completed strings are 00, 01, 10, and 11.In the second test case, the valid completed strings are 00110 and 01100.In the third test case, there are no valid completed strings.In the fourth test case, the only valid completed string is 00110011.
