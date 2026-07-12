# [B. ezraft and Array](https://codeforces.com/contest/2246/problem/B)

---
You are given a single integer n. Construct an array of n distinct positive integers a1,…,an such that for all i(1≤i≤n), a1+a2+a3+…+an is divisible by ai, or determine that no such array exists.

### Input
InputEach test contains multiple test cases. The first line contains the number of test cases t (1≤t≤50). The description of the test cases follows.The first and only line of each test case contains a single integer n(1≤n≤50).

### Output
OutputFor each test case, if there is no solution, output a single integer −1.Otherwise, output n integers a1,…,an(1≤ai≤1017) — an array satisfying the conditions.If there are multiple solutions, print any of them.
NoteIn the first test case, the condition is clearly satisfied, since 1 is divisible by itself.In the second test case, the output is a=[1,9,2,6]. We have a1+a2+a3+a4=18, which is divisible by all ai.
