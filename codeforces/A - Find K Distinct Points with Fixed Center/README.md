# [A. Find K Distinct Points with Fixed Center](https://codeforces.com/contest/1998/problem/A)

---
I couldn't think of a good title for this problem, so I decided to learn from LeetCode.— Sun Tzu, The Art of WarYou are given three integers xcxc, ycyc, and kk (−100≤xc,yc≤100−100≤xc,yc≤100, 1≤k≤10001≤k≤1000). You need to find kk distinct points (x1,y1x1,y1), (x2,y2x2,y2), ……, (xk,ykxk,yk), having integer coordinates, on the 2D coordinate plane such that:   their center∗∗ is (xc,ycxc,yc)  −109≤xi,yi≤109−109≤xi,yi≤109 for all ii from 11 to kk  It can be proven that at least one set of kk distinct points always exists that satisfies these conditions.∗∗The center of kk points (x1,y1x1,y1), (x2,y2x2,y2), ……, (xk,ykxk,yk) is (x1+x2+…+xkk,y1+y2+…+ykk)(x1+x2+…+xkk,y1+y2+…+ykk).

### Input
InputThe first line contains tt (1≤t≤1001≤t≤100) — the number of test cases.Each test case contains three integers xcxc, ycyc, and kk (−100≤xc,yc≤100−100≤xc,yc≤100, 1≤k≤10001≤k≤1000) — the coordinates of the center and the number of distinct points you must output.It is guaranteed that the sum of kk over all test cases does not exceed 10001000.

### Output
OutputFor each test case, output kk lines, the ii-th line containing two space separated integers, xixi and yiyi, (−109≤xi,yi≤109−109≤xi,yi≤109) — denoting the position of the ii-th point.If there are multiple answers, print any of them. It can be shown that a solution always exists under the given constraints.
NoteFor the first test case, (101,101)=(10,10)(101,101)=(10,10).For the second test case, (−1+5−43,−1−1+23)=(0,0)(−1+5−43,−1−1+23)=(0,0).
