# [E. Iva & Pav](https://codeforces.com/contest/1878/problem/E)

---
Iva and Pav are a famous Serbian competitive programming couple. In Serbia, they call Pav "papuca" and that's why he will make all of Iva's wishes come true.Iva gave Pav an array a of n elements.Let's define f(l,r)=al & al+1 &…& ar (here & denotes the bitwise AND operation). Note that f(l,r) is not defined when l>r.Iva also gave Pav q queries.Each query consists of 2 numbers, k and l, and she wants Pav to find the largest index r (l≤r≤n), such that f(l,r)≥k. Pav wants to solve this problem fast because he doesn't want to upset Iva. He needs your help.

### Input
InputThe first line contains a single integer t (1≤t≤104) — the number of test cases.The first line of each test case contains a single integer n (1≤n≤2⋅105) — the length of array a.The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109) — the elements of array a.The third line of each test case contains a single integer q (1≤q≤105) — the number of queries Iva gave Pav.The next q lines of each test case contains two numbers, l and k (1≤l≤n, 1≤k≤109) — the left bound for the subsegment, and the integer k described in statement.It is guaranteed that the sum of n over all test cases does not exceed 2⋅105. Also, it is guaranteed that the sum of q over all test cases does not exceed 2⋅105.

### Output
OutputFor each query output maximal index r (l≤r≤n) such that al & al+1 &…& ar ≥ k.If such r doesn't exist, output −1.
NoteIn the first test case n=5, and the array a=[15,14,17,42,34]The first query asks for the biggest index r such that the f(1,r)≥7.f(1,1)=15, f(1,2)=14, f(1,3)=0 f(1,4)=0 f(1,5)=0, so r=2 is the answer.The second query asks for f(2,r)≥15. Since such r doesn't exist, the answer is −1.The third query asks for f(4,r)≥5. f(4,4)=42, f(4,5)=34, so r=5 is the answer.In the second test case n=5, and the array a=[7,5,3,1,7].For the first query, f(1,r)≥7.f(1,1)=7, f(1,2)=5, f(1,3)=1, f(1,4)=1, f(1,5)=1, so the answer to this query is 1.For the second query, f(5,r)≥7.f(5,5)=7, so the answer is 5.For the third query, f(2,r)≥3.f(2,2)=5, f(2,3)=1, f(2,4)=1, f(2,5)=1, so the answer is 2.
