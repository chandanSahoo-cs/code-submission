# [A. Shohag Loves Mod](https://codeforces.com/contest/2039/problem/A)

---
Shohag has an integer n. Please help him find an increasing integer sequence 1≤a1<a2<…<an≤100 such that aimodi≠ajmodj ∗ is satisfied over all pairs 1≤i<j≤n.It can be shown that such a sequence always exists under the given constraints.∗amodb denotes the remainder of a after division by b. For example, 7mod3=1,8mod4=0 and 69mod10=9.

### Input
InputThe first line contains a single integer t (1≤t≤50) — the number of test cases.The first and only line of each test case contains an integer n (2≤n≤50).

### Output
OutputFor each test case, print n integers — the integer sequence that satisfies the conditions mentioned in the statement. If there are multiple such sequences, output any.
NoteIn the first test case, the sequence is increasing, values are from 1 to 100 and each pair of indices satisfies the condition mentioned in the statement:  For pair (1,2), a1mod1=2mod1=0, and a2mod2=7mod2=1. So they are different.  For pair (1,3), a1mod1=2mod1=0, and a3mod3=8mod3=2. So they are different.  For pair (2,3), a2mod2=7mod2=1, and a3mod3=8mod3=2. So they are different. Note that you do not necessarily have to print the exact same sequence, you can print any other sequence as long as it satisfies the necessary conditions.
