# [D. Coprime](https://codeforces.com/contest/1742/problem/D)

---
Given an array of nn positive integers a1,a2,…,ana1,a2,…,an (1≤ai≤10001≤ai≤1000). Find the maximum value of i+ji+j such that aiai and ajaj are coprime,†† or −1−1 if no such ii, jj exist.For example consider the array [1,3,5,2,4,7,7][1,3,5,2,4,7,7]. The maximum value of i+ji+j that can be obtained is 5+75+7, since a5=4a5=4 and a7=7a7=7 are coprime.†† Two integers pp and qq are coprime if the only positive integer that is a divisor of both of them is 11 (that is, their greatest common divisor is 11).

### Input
InputThe input consists of multiple test cases. The first line contains an integer tt (1≤t≤101≤t≤10) — the number of test cases. The description of the test cases follows.The first line of each test case contains an integer nn (2≤n≤2⋅1052≤n≤2⋅105) — the length of the array.The following line contains nn space-separated positive integers a1a1, a2a2,..., anan (1≤ai≤10001≤ai≤1000) — the elements of the array.It is guaranteed that the sum of nn over all test cases does not exceed 2⋅1052⋅105.

### Output
OutputFor each test case, output a single integer  — the maximum value of i+ji+j such that ii and jj satisfy the condition that aiai and ajaj are coprime, or output −1−1 in case no ii, jj satisfy the condition.
NoteFor the first test case, we can choose i=j=3i=j=3, with sum of indices equal to 66, since 11 and 11 are coprime.For the second test case, we can choose i=7i=7 and j=5j=5, with sum of indices equal to 7+5=127+5=12, since 77 and 44 are coprime.
