# [C1. No Cost Too Great (Easy Version)](https://codeforces.com/contest/2154/problem/C1)

---
This is the easy version of the problem. The difference between the versions is that in this version, bi=1 for all i (1≤i≤n). You can hack only if you solved all versions of this problem. You find yourself with two arrays of positive integers a and b, both of length n. You will perform the following operation any number of times (possibly none):  select an integer i (1≤i≤n) and increase ai by 1. This has a cost of bi. Determine the minimum total cost to make it so that there exists two integers i,j where 1≤i<j≤n and gcd(ai,aj)∗>1.∗gcd(x,y) denotes the greatest common divisor (GCD) of integers x and y.

### Input
InputEach test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows. The first line of each test case contains an integer n (2≤n≤2⋅105) — the length of the array a.The second line of each test case contains n integers a1,a2,…,an (1≤ai≤2⋅105).The third line of each test case contains n integers b1,b2,…,bn (bi=1).The sum of n across all test cases does not exceed 2⋅105.

### Output
OutputFor each testcase, output the minimum cost.
NoteIn the first test case, we can do the following: [1,1]x=1→[2,1]x=2→[2,2]. Now gcd(a1,a2)=gcd(2,2)=2 and so gcd(a1,a2)>1. It can be proven that this is the minimum cost required.In the second test case, it is already true that gcd(a1,a2)=4 and so gcd(a1,a2)>1. So no operations are required.
