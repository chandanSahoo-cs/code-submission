# [A. Perpendicular Segments](https://codeforces.com/contest/2026/problem/A)

---
You are given a coordinate plane and three integers XX, YY, and KK. Find two line segments ABAB and CDCD such that   the coordinates of points AA, BB, CC, and DD are integers;  0≤Ax,Bx,Cx,Dx≤X0≤Ax,Bx,Cx,Dx≤X and 0≤Ay,By,Cy,Dy≤Y0≤Ay,By,Cy,Dy≤Y;  the length of segment ABAB is at least KK;  the length of segment CDCD is at least KK;  segments ABAB and CDCD are perpendicular: if you draw lines that contain ABAB and CDCD, they will cross at a right angle. Note that it's not necessary for segments to intersect. Segments are perpendicular as long as the lines they induce are perpendicular.

### Input
InputThe first line contains a single integer tt (1≤t≤50001≤t≤5000) — the number of test cases. Next, tt cases follow.The first and only line of each test case contains three integers XX, YY, and KK (1≤X,Y≤10001≤X,Y≤1000; 1≤K≤14141≤K≤1414).Additional constraint on the input: the values of XX, YY, and KK are chosen in such a way that the answer exists.

### Output
OutputFor each test case, print two lines. The first line should contain 44 integers AxAx, AyAy, BxBx, and ByBy — the coordinates of the first segment.The second line should also contain 44 integers CxCx, CyCy, DxDx, and DyDy — the coordinates of the second segment.If there are multiple answers, print any of them.
NoteThe answer for the first test case is shown below:    The answer for the second test case:    The answer for the third test case:    The answer for the fourth test case:
