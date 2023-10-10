# [A. Sum of Three](https://codeforces.com/contest/1886/problem/A)

---
Monocarp has an integer nn.He wants to represent his number as a sum of three distinct positive integers xx, yy, and zz. Additionally, Monocarp wants none of the numbers xx, yy, and zz to be divisible by 33.Your task is to help Monocarp to find any valid triplet of distinct positive integers xx, yy, and zz, or report that such a triplet does not exist.

### Input
InputThe first line contains a single integer tt (1≤t≤1041≤t≤104) — the number of testcases.The only line of each testcase contains a single integer nn (1≤n≤1091≤n≤109).

### Output
OutputFor each testcase, if there is no valid triplet xx, yy, and zz, print NO on the first line.Otherwise, print YES on the first line. On the second line, print any valid triplet of distinct positive integers xx, yy, and zz such that x+y+z=nx+y+z=n, and none of the printed numbers are divisible by 33. If there are multiple valid triplets, you can print any of them.
NoteIn the first testcase, one of the valid triplets is x=4x=4, y=5y=5, z=1z=1. None of these numbers are divisible by three, and 4+5+1=104+5+1=10.In the second testcase, there is no valid triplet.In the third testcase, one of the valid triplets is x=2x=2, y=8y=8, z=5z=5. None of these numbers are divisible by three, and 2+8+5=152+8+5=15.In the fourth testcase, there is no valid triplet.
