# [A. Closest Point](https://codeforces.com/contest/2004/problem/A)

---
Consider a set of points on a line. The distance between two points ii and jj is |i−j||i−j|.The point ii from the set is the closest to the point jj from the set, if there is no other point kk in the set such that the distance from jj to kk is strictly less than the distance from jj to ii. In other words, all other points from the set have distance to jj greater or equal to |i−j||i−j|.For example, consider a set of points {1,3,5,8}{1,3,5,8}:  for the point 11, the closest point is 33 (other points have distance greater than |1−3|=2|1−3|=2);  for the point 33, there are two closest points: 11 and 55;  for the point 55, the closest point is 33 (but not 88, since its distance is greater than |3−5||3−5|);  for the point 88, the closest point is 55. You are given a set of points. You have to add an integer point into this set in such a way that it is different from every existing point in the set, and it becomes the closest point to every point in the set. Is it possible?

### Input
InputThe first line contains one integer tt (1≤t≤10001≤t≤1000) — the number of test cases.Each test case consists of two lines:  the first line contains one integer nn (2≤n≤402≤n≤40) — the number of points in the set;  the second line contains nn integers x1,x2,…,xnx1,x2,…,xn (1≤x1<x2<⋯<xn≤1001≤x1<x2<⋯<xn≤100) — the points from the set.

### Output
OutputFor each test case, print YES if it is possible to add a new point according to the conditions from the statement. Otherwise, print NO.
NoteIn the first example, the point 77 will be the closest to both 33 and 88.In the second example, it is impossible to add an integer point so that it becomes the closest to both 55 and 66, and is different from both of them.
