# [A. Rectangle Arrangement](https://codeforces.com/contest/2027/problem/A)

---
You are coloring an infinite square grid, in which all cells are initially white. To do this, you are given nn stamps. Each stamp is a rectangle of width wiwi and height hihi.You will use each stamp exactly once to color a rectangle of the same size as the stamp on the grid in black. You cannot rotate the stamp, and for each cell, the stamp must either cover it fully or not cover it at all. You can use the stamp at any position on the grid, even if some or all of the cells covered by the stamping area are already black.What is the minimum sum of the perimeters of the connected regions of black squares you can obtain after all the stamps have been used?

### Input
InputEach test contains multiple test cases. The first line contains the number of test cases tt (1≤t≤5001≤t≤500). The description of the test cases follows.The first line of each test case contains a single integer nn (1≤n≤1001≤n≤100).The ii-th of the next nn lines contains two integers wiwi and hihi (1≤wi,hi≤1001≤wi,hi≤100).

### Output
OutputFor each test case, output a single integer — the minimum sum of the perimeters of the connected regions of black squares you can obtain after all the stamps have been used.
NoteIn the first test case, the stamps can be used as shown on the left. Each stamp is highlighted in its own color for clarity.  After all these stamps are used, there is one black region (as shown on the right), and its perimeter is 2020. It can be shown that there is no way of using the stamps that yields a lower total perimeter.In the second test case, the second and third stamps can be used entirely inside the first one, so the minimum perimeter is equal to 88.
