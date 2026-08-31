# [E. Chronostasis](https://codeforces.com/contest/2254/problem/E)

---
Yousef has a hidden array a of length n consisting entirely of strictly positive integers.An operation was performed exactly once to create an array b:   Set b1=a1.  For every i from 2 to n, set bi=ai−ai−1.  After this, the elements of b were completely shuffled. You are given the shuffled array b. Reconstruct the lexicographically smallest original array a. If it's impossible for any arrangement of b to produce an array a of strictly positive integers, output −1.

### Input
InputThe first line of input contains an integer t (1≤t≤104) — the number of test cases.The first line of each test case contains an integer n (1≤n≤2⋅105) — the size of the array.The second line of each test case contains n integers b1,b2,…,bn (−109≤bi≤109) — the elements of the shuffled array b.It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

### Output
OutputFor each test case, output n strictly positive integers a1,a2,…,an (ai≥1) — the lexicographically smallest original array a. If it's impossible to create a valid array a, output −1 instead.
NoteIn the first test case, the only valid array is a=[5].In the second test case, there is no valid arrangement of the elements of b that reconstructs an array a consisting entirely of strictly positive integers. Therefore, the answer is −1.In the third test case, one valid arrangement reconstructs the array a=[1,1,3,2,6,3]. The resulting sequence of differences [1,0,2,−1,4,−3] is a permutation of the given array b, and among all valid reconstructions, this array is lexicographically smallest.
