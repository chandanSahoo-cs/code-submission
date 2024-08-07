# [E. Triple Operations](https://codeforces.com/contest/1999/problem/E)

---
On the board Ivy wrote down all integers from ll to rr, inclusive.In an operation, she does the following:   pick two numbers xx and yy on the board, erase them, and in their place write the numbers 3x3x and ⌊y3⌋⌊y3⌋. (Here ⌊∙⌋⌊∙⌋ denotes rounding down to the nearest integer). What is the minimum number of operations Ivy needs to make all numbers on the board equal 00? We have a proof that this is always possible.

### Input
InputThe first line contains an integer tt (1≤t≤1041≤t≤104) — the number of test cases.The only line of each test case contains two integers ll and rr (1≤l<r≤2⋅1051≤l<r≤2⋅105).

### Output
OutputFor each test case, output a single integer — the minimum number of operations needed to make all numbers on the board equal 00.
NoteIn the first test case, we can perform 55 operations as follows: 1,2,3→x=1,y=23,0,3→x=0,y=31,0,3→x=0,y=31,0,1→x=0,y=10,0,1→x=0,y=10,0,0.1,2,3−→−−−−x=1,y=23,0,3−→−−−−x=0,y=31,0,3−→−−−−x=0,y=31,0,1−→−−−−x=0,y=10,0,1−→−−−−x=0,y=10,0,0.
