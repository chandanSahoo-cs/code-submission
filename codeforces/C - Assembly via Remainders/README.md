# [C. Assembly via Remainders](https://codeforces.com/contest/1968/problem/C)

---
You are given an array x2,x3,…,xnx2,x3,…,xn. Your task is to find any array a1,…,ana1,…,an, where:   1≤ai≤1091≤ai≤109 for all 1≤i≤n1≤i≤n.  xi=aimodai−1xi=aimodai−1 for all 2≤i≤n2≤i≤n. Here cmoddcmodd denotes the remainder of the division of the integer cc by the integer dd. For example 5mod2=15mod2=1, 72mod3=072mod3=0, 143mod14=3143mod14=3.Note that if there is more than one aa which satisfies the statement, you are allowed to find any.

### Input
InputThe first line contains a single integer tt (1≤t≤104)(1≤t≤104) — the number of test cases.The first line of each test case contains a single integer nn (2≤n≤500)(2≤n≤500) — the number of elements in aa.The second line of each test case contains n−1n−1 integers x2,…,xnx2,…,xn (1≤xi≤500)(1≤xi≤500) — the elements of xx.It is guaranteed that the sum of values nn over all test cases does not exceed 2⋅1052⋅105.

### Output
OutputFor each test case output any a1,…,ana1,…,an (1≤ai≤1091≤ai≤109) which satisfies the statement.
NoteIn the first test case a=[3,5,4,9]a=[3,5,4,9] satisfies the conditions, because:   a2moda1=5mod3=2=x2a2moda1=5mod3=2=x2;  a3moda2=4mod5=4=x3a3moda2=4mod5=4=x3;  a4moda3=9mod4=1=x4a4moda3=9mod4=1=x4;
