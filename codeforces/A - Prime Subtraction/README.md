# [A. Prime Subtraction](https://codeforces.com/contest/1238/problem/A)

---
You are given two integers xx and yy (it is guaranteed that x>yx>y). You may choose any prime integer pp and subtract it any number of times from xx. Is it possible to make xx equal to yy?Recall that a prime number is a positive integer that has exactly two positive divisors: 11 and this integer itself. The sequence of prime numbers starts with 22, 33, 55, 77, 1111.Your program should solve tt independent test cases.

### Input
InputThe first line contains one integer tt (1≤t≤10001≤t≤1000) — the number of test cases.Then tt lines follow, each describing a test case. Each line contains two integers xx and yy (1≤y<x≤10181≤y<x≤1018).

### Output
OutputFor each test case, print YES if it is possible to choose a prime number pp and subtract it any number of times from xx so that xx becomes equal to yy. Otherwise, print NO.You may print every letter in any case you want (so, for example, the strings yEs, yes, Yes, and YES will all be recognized as positive answer).
NoteIn the first test of the example you may choose p=2p=2 and subtract it once.In the second test of the example you may choose p=5p=5 and subtract it twice. Note that you cannot choose p=7p=7, subtract it, then choose p=3p=3 and subtract it again.In the third test of the example you may choose p=3p=3 and subtract it 333333333333333333333333333333333333 times.
