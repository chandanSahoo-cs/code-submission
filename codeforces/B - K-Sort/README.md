# [B. K-Sort](https://codeforces.com/contest/1987/problem/B)

---
You are given an array of integers a of length n. You can apply the following operation any number of times (maybe, zero):   First, choose an integer k such that 1≤k≤n and pay k+1 coins.  Then, choose exactly k indices such that 1≤i1<i2<…<ik≤n.  Then, for each x from 1 to k, increase aix by 1. Find the minimum number of coins needed to make a non-decreasing. That is, a1≤a2≤…≤an.

### Input
InputEach test contains multiple test cases. The first line of input contains a single integer t (1≤t≤104) — the number of test cases. The description of the test cases follows.The first line of each test case contains a single integer n (1≤n≤105) — the length of the array a.The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109) — the elements of the array a.It is guaranteed that the sum of n over all test cases does not exceed 105.

### Output
OutputFor each test case, output a single integer — the minimum number of coins needed to make a non-decreasing.
NoteIn the first test case, a is already sorted, so you don't have to spend any coins.In the second test case, the optimal sequence of operations is:   Choose k=2 and the indices 2 and 5: [2,1,4,7,6]→[2,2,4,7,7]. This costs 3 coins.  It can be proven that it is not possible to make a non-decreasing by spending less than 3 coins.
