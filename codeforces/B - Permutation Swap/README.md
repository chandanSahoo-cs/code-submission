# [B. Permutation Swap](https://codeforces.com/contest/1828/problem/B)

---
You are given an unsorted permutation p1,p2,…,pn. To sort the permutation, you choose a constant k (k≥1) and do some operations on the permutation. In one operation, you can choose two integers i, j (1≤j<i≤n) such that i−j=k, then swap pi and pj.What is the maximum value of k that you can choose to sort the given permutation?A permutation is an array consisting of n distinct integers from 1 to n in arbitrary order. For example, [2,3,1,5,4] is a permutation, but [1,2,2] is not a permutation (2 appears twice in the array) and [1,3,4] is also not a permutation (n=3 but there is 4 in the array).An unsorted permutation p is a permutation such that there is at least one position i that satisfies pi≠i.

### Input
InputEach test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows.The first line of each test case contains a single integer n (2≤n≤105) — the length of the permutation p.The second line of each test case contains n distinct integers p1,p2,…,pn (1≤pi≤n) — the permutation p. It is guaranteed that the given numbers form a permutation of length n and the given permutation is unsorted.It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

### Output
OutputFor each test case, output the maximum value of k that you can choose to sort the given permutation.We can show that an answer always exists.
NoteIn the first test case, the maximum value of k you can choose is 1. The operations used to sort the permutation are:   Swap p2 and p1 (2−1=1) → p=[1,3,2]  Swap p2 and p3 (3−2=1) → p=[1,2,3] In the second test case, the maximum value of k you can choose is 2. The operations used to sort the permutation are:   Swap p3 and p1 (3−1=2) → p=[1,4,3,2]  Swap p4 and p2 (4−2=2) → p=[1,2,3,4]
