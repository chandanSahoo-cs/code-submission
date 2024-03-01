# [A. Too Min Too Max](https://codeforces.com/contest/1934/problem/A)

---
Given an array a of n elements, find the maximum value of the expression:|ai−aj|+|aj−ak|+|ak−al|+|al−ai|where i, j, k, and l are four distinct indices of the array a, with 1≤i,j,k,l≤n.Here |x| denotes the absolute value of x.

### Input
InputThe first line contains one integer t (1≤t≤500) — the number of test cases. The description of the test cases follows.The first line of each test case contains a single integer n (4≤n≤100) — the length of the given array.The second line of each test case contains n integers a1,a2,…,an (−106≤ai≤106).

### Output
OutputFor each test case, print a single integer — the maximum value.
NoteIn the first test case, for any selection of i, j, k, l, the answer will be 0. For example, |a1−a2|+|a2−a3|+|a3−a4|+|a4−a1|=|1−1|+|1−1|+|1−1|+|1−1|=0+0+0+0=0.In the second test case, for i=1, j=3, k=2, and l=5, the answer will be 6. |a1−a3|+|a3−a2|+|a2−a5|+|a5−a1|=|1−2|+|2−1|+|1−3|+|3−1|=1+1+2+2=6.
