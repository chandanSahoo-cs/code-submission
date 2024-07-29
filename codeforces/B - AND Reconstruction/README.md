# [B. AND Reconstruction](https://codeforces.com/contest/1991/problem/B)

---
You are given an array bb of n−1n−1 integers.An array aa of nn integers is called good if bi=ai&ai+1bi=ai&ai+1 for 1≤i≤n−11≤i≤n−1, where && denotes the bitwise AND operator.Construct a good array, or report that no good arrays exist.

### Input
InputEach test contains multiple test cases. The first line contains a single integer tt (1≤t≤1041≤t≤104) — the number of test cases. The description of test cases follows.The first line of each test case contains a single integer nn (2≤n≤1052≤n≤105) — the length of the array aa.The second line of each test case contains n−1n−1 integers b1,b2,…,bn−1b1,b2,…,bn−1 (0≤bi<2300≤bi<230) — the elements of the array bb.It is guaranteed that the sum of nn over all test cases does not exceed 105105.

### Output
OutputFor each test case, output a single integer −1−1 if no good arrays exist. Otherwise, output nn space-separated integers a1,a2,…,ana1,a2,…,an (0≤ai<2300≤ai<230) — the elements of a good array aa.If there are multiple solutions, you may output any of them.
NoteIn the first test case, b=[1]b=[1]. A possible good array is a=[5,3]a=[5,3], because a1&a2=5&3=1=b1a1&a2=5&3=1=b1.In the second test case, b=[2,0]b=[2,0]. A possible good array is a=[3,2,1]a=[3,2,1], because a1&a2=3&2=2=b1a1&a2=3&2=2=b1 and a2&a3=2&1=0=b2a2&a3=2&1=0=b2.In the third test case, b=[1,2,3]b=[1,2,3]. It can be shown that no good arrays exist, so the output is −1−1.In the fourth test case, b=[3,5,4,2]b=[3,5,4,2]. A possible good array is a=[3,7,5,6,3]a=[3,7,5,6,3].
