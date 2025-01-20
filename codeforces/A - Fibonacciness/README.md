# [A. Fibonacciness](https://codeforces.com/contest/2060/problem/A)

---
There is an array of 5 integers. Initially, you only know a1,a2,a4,a5. You may set a3 to any positive integer, negative integer, or zero. The Fibonacciness of the array is the number of integers i (1≤i≤3) such that ai+2=ai+ai+1. Find the maximum Fibonacciness over all integer values of a3.

### Input
InputThe first line contains an integer t (1≤t≤500) — the number of test cases.The only line of each test case contains four integers a1,a2,a4,a5 (1≤ai≤100).

### Output
OutputFor each test case, output the maximum Fibonacciness on a new line.
NoteIn the first test case, we can set a3 to 2 to achieve the maximal Fibonacciness of 3.In the third test case, it can be shown that 2 is the maximum Fibonacciness that can be achieved. This can be done by setting a3 to 18.
