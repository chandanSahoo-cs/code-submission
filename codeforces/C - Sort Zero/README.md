# [C. Sort Zero](https://codeforces.com/contest/1712/problem/C)

---
An array is sorted if it has no inversionsA Young BoyYou are given an array of n positive integers a1,a2,…,an. In one operation you do the following:   Choose any integer x.  For all i such that ai=x, do ai:=0 (assign 0 to ai). Find the minimum number of operations required to sort the array in non-decreasing order.

### Input
InputEach test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). Description of the test cases follows.The first line of each test case contains a single integer n (1≤n≤105).The second line of each test case contains n positive integers a1,a2,…,an (1≤ai≤n).It is guaranteed that the sum of n over all test cases does not exceed 105.

### Output
OutputFor each test case print one integer — the minimum number of operations required to sort the array in non-decreasing order.
NoteIn the first test case, you can choose x=3 for the operation, the resulting array is [0,0,2].In the second test case, you can choose x=1 for the first operation and x=3 for the second operation, the resulting array is [0,0,0,0].
