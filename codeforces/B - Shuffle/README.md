# [B. Shuffle](https://codeforces.com/contest/1366/problem/B)

---
You are given an array consisting of n integers a1, a2, ..., an. Initially ax=1, all other elements are equal to 0.You have to perform m operations. During the i-th operation, you choose two indices c and d such that li≤c,d≤ri, and swap ac and ad.Calculate the number of indices k such that it is possible to choose the operations so that ak=1 in the end.

### Input
InputThe first line contains a single integer t (1≤t≤100) — the number of test cases. Then the description of t testcases follow.The first line of each test case contains three integers n, x and m (1≤n≤109; 1≤m≤100; 1≤x≤n).Each of next m lines contains the descriptions of the operations; the i-th line contains two integers li and ri (1≤li≤ri≤n).

### Output
OutputFor each test case print one integer — the number of indices k such that it is possible to choose the operations so that ak=1 in the end.
NoteIn the first test case, it is possible to achieve ak=1 for every k. To do so, you may use the following operations:  swap ak and a4;  swap a2 and a2;  swap a5 and a5. In the second test case, only k=1 and k=2 are possible answers. To achieve a1=1, you have to swap a1 and a1 during the second operation. To achieve a2=1, you have to swap a1 and a2 during the second operation.
