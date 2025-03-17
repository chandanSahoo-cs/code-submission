# [C. Breach of Faith](https://codeforces.com/contest/2078/problem/C)

---
Breach of Faith - Supire feat.eili You and your team have worked tirelessly until you have a sequence a1,a2,…,a2n+1 of positive integers satisfying these properties.  1≤ai≤1018 for all 1≤i≤2n+1.  a1,a2,…,a2n+1 are pairwise distinct.  a1=a2−a3+a4−a5+…+a2n−a2n+1. However, the people you worked with sabotaged you because they wanted to publish this sequence first. They deleted one number from this sequence and shuffled the rest, leaving you with a sequence b1,b2,…,b2n. You have forgotten the sequence a and want to find a way to recover it.If there are many possible sequences, you can output any of them. It can be proven under the constraints of the problem that at least one sequence a exists.

### Input
InputEach test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows. The first line of each test case contains one integer n (1≤n≤2⋅105).The second line of each test case contains 2n distinct integers b1,b2,…,b2n (1≤bi≤109), denoting the sequence b.It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

### Output
OutputFor each test case, output 2n+1 distinct integers, denoting the sequence a (1≤ai≤1018). If there are multiple possible sequences, you can output any of them. The sequence a should satisfy the given conditions, and it should be possible to obtain b after deleting one element from a and shuffling the remaining elements.
