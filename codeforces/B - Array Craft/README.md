# [B. Array Craft](https://codeforces.com/contest/1990/problem/B)

---
For an array b of size m, we define: the maximum prefix position of b is the smallest index i that satisfies b1+…+bi=maxmj=1(b1+…+bj); the maximum suffix position of b is the largest index i that satisfies bi+…+bm=maxmj=1(bj+…+bm).You are given three integers n, x, and y (x>y). Construct an array a of size n satisfying: ai is either 1 or −1 for all 1≤i≤n; the maximum prefix position of a is x; the maximum suffix position of a is y.If there are multiple arrays that meet the conditions, print any. It can be proven that such an array always exists under the given conditions.

### Input
InputThe first line contains an integer t (1≤t≤104) — the number of test cases.For each test case:   The only line contains three integers n, x, and y (2≤n≤105,1≤y<x≤n). It is guaranteed that the sum of n over all test cases will not exceed 105.

### Output
OutputFor each test case, output n space-separated integers a1,a2,…,an in a new line.
NoteIn the second test case,  i=x=4 is the smallest index that satisfies a1+…+ai=maxnj=1(a1+…+aj)=2; i=y=3 is the greatest index that satisfies ai+…+an=maxnj=1(aj+…+an)=2.Thus, the array a=[1,−1,1,1] is considered correct.
