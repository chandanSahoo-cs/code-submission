# [B. Minimize Inversions](https://codeforces.com/contest/1918/problem/B)

---
You are given two permutations a and b of length n. A permutation is an array of n elements from 1 to n where all elements are distinct. For example, an array [2,1,3] is a permutation, but [0,1] and [1,3,1] aren't.You can (as many times as you want) choose two indices i and j, then swap ai with aj and bi with bj simultaneously. You hate inversions, so you want to minimize the total number of inversions in both permutations.An inversion in a permutation p is a pair of indices (i,j) such that i<j and pi>pj. For example, if p=[3,1,4,2,5] then there are 3 inversions in it (the pairs of indices are (1,2), (1,4) and (3,4)).

### Input
InputThe first line contains an integer t (1≤t≤20000) — the number of test cases.Each test case consists of three lines. The first line contains an integer n (1≤n≤2⋅105) — the length of the permutations a and b. The second line contains n integers a1,a2,…,an (1≤ai≤n) — permutation a. The third line contains b in a similar format. It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

### Output
OutputFor each test case, output two permutations a′ and b′ (in the same format as in the input) — the permutations after all operations. The total number of inversions in a′ and b′ should be the minimum possible among all pairs of permutations that can be obtained using operations from the statement.If there are multiple solutions, print any of them.
NoteIn the first test case, the minimum possible number of inversions is 10.In the second test case, we can sort both permutations at the same time. For this, the following operations can be done:  Swap the elements in the positions 1 and 3 in both permutations. After the operation, a= [2,1,3], b= [2,1,3].  Swap the elements in the positions 1 and 2. After the operations, a and b are sorted. In the third test case, the minimum possible number of inversions is 7.
