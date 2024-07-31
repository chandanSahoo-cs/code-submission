# [B. Make Three Regions](https://codeforces.com/contest/1997/problem/B)

---
There is a grid, consisting of 22 rows and nn columns. Each cell of the grid is either free or blocked.A free cell yy is reachable from a free cell xx if at least one of these conditions holds:   xx and yy share a side;  there exists a free cell zz such that zz is reachable from xx and yy is reachable from zz. A connected region is a set of free cells of the grid such that all cells in it are reachable from one another, but adding any other free cell to the set violates this rule.For example, consider the following layout, where white cells are free, and dark grey cells are blocked:   There are 33 regions in it, denoted with red, green and blue color respectively:   The given grid contains at most 11 connected region. Your task is to calculate the number of free cells meeting the following constraint:  if this cell is blocked, the number of connected regions becomes exactly 33.

### Input
InputThe first line contains a single integer tt (1≤t≤1041≤t≤104) — the number of test cases.The first line of each test case contains a single integer nn (1≤n≤2⋅1051≤n≤2⋅105) — the number of columns.The ii-th of the next two lines contains a description of the ii-th row of the grid — the string sisi, consisting of nn characters. Each character is either . (denoting a free cell) or x (denoting a blocked cell). Additional constraint on the input:   the given grid contains at most 11 connected region;  the sum of nn over all test cases doesn't exceed 2⋅1052⋅105.

### Output
OutputFor each test case, print a single integer — the number of cells such that the number of connected regions becomes 33 if this cell is blocked.
NoteIn the first test case, if the cell (1,3)(1,3) is blocked, the number of connected regions becomes 33 (as shown in the picture from the statement).
