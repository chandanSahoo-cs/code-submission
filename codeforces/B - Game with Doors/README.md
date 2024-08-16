# [B. Game with Doors](https://codeforces.com/contest/2004/problem/B)

---
There are 100100 rooms arranged in a row and 9999 doors between them; the ii-th door connects rooms ii and i+1i+1. Each door can be either locked or unlocked. Initially, all doors are unlocked.We say that room xx is reachable from room yy if all doors between them are unlocked.You know that:   Alice is in some room from the segment [l,r][l,r];  Bob is in some room from the segment [L,R][L,R];  Alice and Bob are in different rooms. However, you don't know the exact rooms they are in.You don't want Alice and Bob to be able to reach each other, so you are going to lock some doors to prevent that. What's the smallest number of doors you have to lock so that Alice and Bob cannot meet, regardless of their starting positions inside the given segments?

### Input
InputThe first line contains a single integer tt (1≤t≤1041≤t≤104) — the number of test cases.The first line of each test case contains two integers ll and rr (1≤l<r≤1001≤l<r≤100) — the bounds of the segment of rooms where Alice is located.The second line of each test case contains two integers LL and RR (1≤L<R≤1001≤L<R≤100) — the bounds of the segment of rooms where Bob is located.

### Output
OutputFor each test case, print a single integer — the smallest number of doors you have to lock so that Alice and Bob cannot meet, regardless of their starting positions inside the given segments.
NoteIn the first test case, it is sufficient to lock the door between rooms 22 and 33.In the second test case, the following doors have to be locked: (2,3)(2,3), (3,4)(3,4), (4,5)(4,5).In the third test case, the following doors have to be locked: (5,6)(5,6) and (6,7)(6,7).
