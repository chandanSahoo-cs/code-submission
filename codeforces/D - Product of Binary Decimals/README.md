# [D. Product of Binary Decimals](https://codeforces.com/contest/1950/problem/D)

---
Let's call a number a binary decimal if it is a positive integer and all digits in its decimal notation are either 0 or 1. For example, 1010111 is a binary decimal, while 10201 and 787788 are not.Given a number n, you are asked whether or not it is possible to represent n as a product of some (not necessarily distinct) binary decimals.

### Input
InputThe first line contains a single integer t (1≤t≤5⋅104) — the number of test cases.The only line of each test case contains a single integer n (1≤n≤105).

### Output
OutputFor each test case, output "YES" (without quotes) if n can be represented as a product of binary decimals, and "NO" (without quotes) otherwise.You can output "YES" and "NO" in any case (for example, strings "yES", "yes", and "Yes" will be recognized as a positive response).
NoteThe first five test cases can be represented as a product of binary decimals as follows:   121=11×11.  1=1 is already a binary decimal.  14641=11×11×11×11.  12221=11×11×101.  10110=10110 is already a binary decimal.
