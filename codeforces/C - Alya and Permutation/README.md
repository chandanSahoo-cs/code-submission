# [C. Alya and Permutation](https://codeforces.com/contest/2035/problem/C)

---
Alya has been given a hard problem. Unfortunately, she is too busy running for student council. Please solve this problem for her.Given an integer nn, construct a permutation p of integers 1,2,…,n that maximizes the value of k (which is initially 0) after the following process.Perform n operations, on the i-th operation (i=1,2,…,n),  If i is odd, k=k&pi, where & denotes the bitwise AND operation.  If i is even, k=k|pi, where | denotes the bitwise OR operation.

### Input
InputThe first line contains a single integer t (1≤t≤500) — the number of test cases.The only line of each test case contains a single integer n (5≤n≤2⋅105) — the length of the permutation.It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

### Output
OutputFor each test case, output the maximum value of k in the first line and output the permutation p1,p2,…,pn in the second line.If there are multiple such permutations, output any.
NoteFor the first test case, the value of k is determined as follows:k=0 initially. On the 1st operation, 1 is odd, so Alya sets k to be k&p1=0&2=0. On the 2nd operation, 2 is even, so Alya sets k to be k|p2=0|1=1. On the 3rd operation, 3 is odd, so Alya sets k to be k&p3=1&3=1. On the 4th operation, 4 is even, so Alya sets k to be k|p4=1|4=5. On the 5th operation, 5 is odd, so Alya sets k to be k&p5=5&5=5.The final value of k is 5. It can be shown that the final value of k is at most 5 for all permutations of length 5. Another valid output is [2,3,1,4,5].For the second test case, the final value of k is 7. It can be shown that the final value of k is at most 7 for all permutations of length 6. Other valid outputs include [2,4,1,6,3,5] and [5,2,6,1,3,4].
