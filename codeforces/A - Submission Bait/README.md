# [A. Submission Bait](https://codeforces.com/contest/1990/problem/A)

---
Alice and Bob are playing a game in an array aa of size n.They take turns to do operations, with Alice starting first. The player who can not operate will lose. At first, a variable mx is set to 0.In one operation, a player can do: Choose an index i (1≤i≤n) such that ai≥mx and set mx to ai. Then, set ai to 0.Determine whether Alice has a winning strategy.

### Input
InputThe first line contains an integer t (1≤t≤103) — the number of test cases.For each test case:   The first line contains an integer n (2≤n≤50) — the size of the array.  The second line contains n integers a1,a2,…,an (1≤ai≤n) — the elements of the array.

### Output
OutputFor each test case, if Alice has a winning strategy, output "YES". Otherwise, output "NO".You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.
NoteIn the first test case, Alice can choose i=1 since a1=2≥mx=0.After Alice's operation, a=[0,1] and mx=2. Bob can not do any operation. Alice wins.In the second test case, Alice doesn't have a winning strategy.For example, if Alice chooses i=1, after Alice's operation: a=[0,1] and mx=1. Then, Bob can choose i=2 since a2=1≥mx=1. After Bob's operation: a=[0,0] and mx=1. Alice can not do any operation. Bob wins.
