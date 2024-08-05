# [B. Parity and Sum](https://codeforces.com/contest/1993/problem/B)

---
Given an array aa of nn positive integers.In one operation, you can pick any pair of indexes (i,j)(i,j) such that aiai and ajaj have distinct parity, then replace the smaller one with the sum of them. More formally:   If ai<ajai<aj, replace aiai with ai+ajai+aj;  Otherwise, replace ajaj with ai+ajai+aj. Find the minimum number of operations needed to make all elements of the array have the same parity.

### Input
InputThe first line contains a single integer tt (1≤t≤1041≤t≤104) — the number of test cases.The first line of each test case contains a single integer nn (1≤n≤2⋅1051≤n≤2⋅105).The second line contains nn integers a1,a2,…,ana1,a2,…,an (1≤ai≤1091≤ai≤109) — the elements of array aa.It is guaranteed that the sum of nn over all test cases does not exceed 2⋅1052⋅105.

### Output
OutputFor each test case, output a single integer — the minimum number of operations required.
NoteIn the first test case, all integers already have the same parity. Therefore, no operation is needed.In the third test case, we can perform two operations (1,2)(1,2) and (1,3)(1,3). The array aa transforms as follows: a=[2,3,4]⟶[5,3,4]⟶[5,3,9]a=[2,3,4]⟶[5,3,4]⟶[5,3,9].In the fourth test case, an example of an optimal sequence of operations is (1,2)(1,2), (1,3)(1,3), (1,4)(1,4), and (1,4)(1,4). The array aa transforms as follows: a=[3,2,2,8]⟶[3,5,2,8]⟶[3,5,5,8]⟶[11,5,5,8]⟶[11,5,5,19]a=[3,2,2,8]⟶[3,5,2,8]⟶[3,5,5,8]⟶[11,5,5,8]⟶[11,5,5,19].
