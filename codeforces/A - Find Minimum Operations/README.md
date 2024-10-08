# [A. Find Minimum Operations](https://codeforces.com/contest/2020/problem/A)

---
You are given two integers nn and kk.In one operation, you can subtract any power of kk from nn. Formally, in one operation, you can replace nn by (n−kx)(n−kx) for any non-negative integer xx.Find the minimum number of operations required to make nn equal to 00.

### Input
InputEach test contains multiple test cases. The first line contains the number of test cases tt (1≤t≤1041≤t≤104). The description of the test cases follows.The only line of each test case contains two integers nn and kk (1≤n,k≤1091≤n,k≤109).

### Output
OutputFor each test case, output the minimum number of operations on a new line.
NoteIn the first test case, n=5n=5 and k=2k=2. We can perform the following sequence of operations:  Subtract 20=120=1 from 55. The current value of nn becomes 5−1=45−1=4.  Subtract 22=422=4 from 44. The current value of nn becomes 4−4=04−4=0. It can be shown that there is no way to make nn equal to 00 in less than 22 operations. Thus, 22 is the answer.In the second test case, n=3n=3 and k=5k=5. We can perform the following sequence of operations:  Subtract 50=150=1 from 33. The current value of nn becomes 3−1=23−1=2.  Subtract 50=150=1 from 22. The current value of nn becomes 2−1=12−1=1.  Subtract 50=150=1 from 11. The current value of nn becomes 1−1=01−1=0. It can be shown that there is no way to make nn equal to 00 in less than 33 operations. Thus, 33 is the answer.
