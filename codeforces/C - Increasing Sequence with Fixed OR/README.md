# [C. Increasing Sequence with Fixed OR](https://codeforces.com/contest/1988/problem/C)

---
You are given a positive integer n. Find the longest sequence of positive integers a=[a1,a2,…,ak] that satisfies the following conditions, and print the sequence:  ai≤n for all 1≤i≤k.  a is strictly increasing. That is, ai>ai−1 for all 2≤i≤k.  ai|ai−1=n for all 2≤i≤k, where | denotes the bitwise OR operation.

### Input
InputEach test contains multiple test cases. The first line contains the number of test cases t (1≤t≤1000). Description of the test cases follows.The only line of each test case contains one integer n (1≤n≤1018).It's guaranteed that the sum of lengths of the longest valid sequences does not exceed 5⋅105.

### Output
OutputFor each testcase, print two lines. In the first line, print the length of your constructed sequence, k. In the second line, print k positive integers, denoting the sequence. If there are multiple longest sequences, you can print any of them.
