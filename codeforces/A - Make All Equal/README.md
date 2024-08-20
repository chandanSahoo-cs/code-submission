# [A. Make All Equal](https://codeforces.com/contest/2001/problem/A)

---
You are given a cyclic array a1,a2,…,ana1,a2,…,an.You can perform the following operation on a at most n−1 times:  Let m be the current size of a, you can choose any two adjacent elements where the previous one is no greater than the latter one (In particular, am and a1 are adjacent and am is the previous one), and delete exactly one of them. In other words, choose an integer i (1≤i≤m) where ai≤a(imodm)+1 holds, and delete exactly one of ai or a(imodm)+1 from a. Your goal is to find the minimum number of operations needed to make all elements in a equal.

### Input
InputEach test contains multiple test cases. The first line contains the number of test cases t (1≤t≤500). The description of the test cases follows.The first line of each test case contains a single integer n (1≤n≤100) — the length of the array a.The second line of each test case contains n integers a1,a2,…,an (1≤ai≤n) — the elements of array a.

### Output
OutputFor each test case, output a single line containing an integer: the minimum number of operations needed to make all elements in a equal.
NoteIn the first test case, there is only one element in a, so we can't do any operation.In the second test case, we can perform the following operations to make all elements in a equal:  choose i=2, delete a3, then a would become [1,2].  choose i=1, delete a1, then a would become [2]. It can be proven that we can't make all elements in a equal using fewer than 2 operations, so the answer is 2.
