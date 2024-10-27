# [B. Everyone Loves Tres](https://codeforces.com/contest/2035/problem/B)

---
There are 3 heroes and 3 villains, so 6 people in total.Given a positive integer n. Find the smallest integer whose decimal representation has length n and consists only of 3s and 6s such that it is divisible by both 33 and 66. If no such integer exists, print −1.

### Input
InputThe first line contains a single integer t (1≤t≤500) — the number of test cases.The only line of each test case contains a single integer n (1≤n≤500) — the length of the decimal representation.

### Output
OutputFor each test case, output the smallest required integer if such an integer exists and −1 otherwise.
NoteFor n=1, no such integer exists as neither 3 nor 6 is divisible by 33.For n=2, 66 consists only of 6s and it is divisible by both 33 and 66.For n=3, no such integer exists. Only 363 is divisible by 33, but it is not divisible by 66.For n=4, 3366 and 6666 are divisible by both 33 and 66, and 3366 is the smallest.
