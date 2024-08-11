# [A. Distanced Coloring](https://codeforces.com/contest/2002/problem/A)

---
You received an n×m grid from a mysterious source. The source also gave you a magic positive integer constant k.The source told you to color the grid with some colors, satisfying the following condition:  If (x1,y1), (x2,y2) are two distinct cells with the same color, then max(|x1−x2|,|y1−y2|)≥k. You don't like using too many colors. Please find the minimum number of colors needed to color the grid.

### Input
InputEach test contains multiple test cases. The first line contains the number of test cases t (1≤t≤1000). The description of the test cases follows.The only line of each test case consists of three positive integers n, m, k (1≤n,m,k≤104) — the dimensions of the grid and the magic constant.

### Output
OutputFor each test case, print a single integer — the minimum number of colors needed to color the grid.
NoteIn the first test case, one of the optimal constructions is:  In the second test case, the color of all cells must be pairwise different, so the answer is 5.
