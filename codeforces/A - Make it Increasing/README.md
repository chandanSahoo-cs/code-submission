# [A. Make it Increasing](https://codeforces.com/contest/1667/problem/A)

---
You are given an array a consisting of n positive integers, and an array b, with length n. Initially bi=0 for each 1≤i≤n.In one move you can choose an integer i (1≤i≤n), and add ai to bi or subtract ai from bi. What is the minimum number of moves needed to make b increasing (that is, every element is strictly greater than every element before it)?

### Input
InputThe first line contains a single integer n (2≤n≤5000).The second line contains n integers, a1, a2, ..., an (1≤ai≤109) — the elements of the array a.

### Output
OutputPrint a single integer, the minimum number of moves to make b increasing.
NoteExample 1: you can subtract a1 from b1, and add a3, a4, and a5 to b3, b4, and b5 respectively. The final array will be [−1, 0, 3, 4, 5] after 4 moves.Example 2: you can reach [−3, −2, −1, 0, 1, 2, 3] in 10 moves.
