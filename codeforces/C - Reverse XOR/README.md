# [C. Reverse XOR](https://codeforces.com/contest/2160/problem/C)

---
Given a positive integer x, let f(x) be the positive integer formed by reversing the binary representation of x without leading zeroes. For example, if x=12=11002, then f(x)=00112=3. You are given an integer n. Please determine if there exists a positive integer x such that x⊕f(x)=n∗.∗Here, ⊕ denotes the bitwise XOR operation.

### Input
InputEach test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows. The first line of each test case contains an integer n (0≤n<230).

### Output
OutputFor each test case, output YES if there exists a positive integer x such that x⊕f(x)=n, and NO otherwise.You can output the answer in any case. For example, the strings "yEs", "yes", and "Yes" are also recognized as positive responses.
NoteIn the first case, when x=1, f(x)=1, and x⊕f(x)=0. Thus, the answer is YES.In the second case, when x=2, f(x)=1, and x⊕f(x)=3. Thus, the answer is YES.In the fourth test case, we can show there is no x that satisfies x⊕f(x)=8, so the answer is NO.
