# [B. Longest Divisors Interval](https://codeforces.com/contest/1855/problem/B)

---
Given a positive integer n, find the maximum size of an interval [l,r] of positive integers such that, for every i in the interval (i.e., l≤i≤r), n is a multiple of i.Given two integers l≤r, the size of the interval [l,r] is r−l+1 (i.e., it coincides with the number of integers belonging to the interval).

### Input
InputThe first line contains a single integer t (1≤t≤104) — the number of test cases.The only line of the description of each test case contains one integer n (1≤n≤1018).

### Output
OutputFor each test case, print a single integer: the maximum size of a valid interval.
NoteIn the first test case, a valid interval with maximum size is [1,1] (it's valid because n=1 is a multiple of 1) and its size is 1.In the second test case, a valid interval with maximum size is [4,5] (it's valid because n=40 is a multiple of 4 and 5) and its size is 2.In the third test case, a valid interval with maximum size is [9,11].In the fourth test case, a valid interval with maximum size is [8,13].In the seventh test case, a valid interval with maximum size is [327869,327871].
