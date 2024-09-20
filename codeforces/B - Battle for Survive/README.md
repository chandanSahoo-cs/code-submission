# [B. Battle for Survive](https://codeforces.com/contest/2013/problem/B)

---
Eralim, being the mafia boss, manages a group of n fighters. Fighter i has a rating of ai.Eralim arranges a tournament of n−1 battles, in each of which two not yet eliminated fighters i and j (1≤i<j≤n) are chosen, and as a result of the battle, fighter i is eliminated from the tournament, and the rating of fighter j is reduced by the rating of fighter i. That is, aj is decreased by ai. Note that fighter j's rating can become negative. The fighters indexes do not change.Eralim wants to know what maximum rating the last remaining fighter can preserve if he chooses the battles optimally.

### Input
InputEach test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows.The first line of each test case contains a single integer n (2≤n≤2⋅105) — the number of fighters.The second line of each test case contains n integers a1,a2,…an (1≤ai≤109) — the ratings of the fighters.The sum of n over all testcases does not exceed 2⋅105.

### Output
OutputFor each testcase, output a single integer — the maximum rating that the last remaining fighter can preserve.
NoteIn the first example, you can arrange a fight between fighters with indices 1 and 2, where the fighter with index 2 will win. The rating of the last fighter, that is, the fighter with index 2, will be 1−2=−1.In the second example, you can first conduct a fight between fighters with indices 1 and 2, where the fighter with index 2 will win, and then conduct a fight between fighters with indices 2 and 3, where the fighter with index 3 will win.The rating of the fighter with index 2 after the first fight will be 2−2=0. The rating of the fighter with index 3 after the second fight will be 8−0=8.
