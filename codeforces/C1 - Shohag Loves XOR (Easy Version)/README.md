# [C1. Shohag Loves XOR (Easy Version)](https://codeforces.com/contest/2039/problem/C1)

---
This is the easy version of the problem. The differences between the two versions are highlighted in bold. You can only make hacks if both versions of the problem are solved.Shohag has two integers x and m. Help him count the number of integers 1≤y≤m such that x≠y and x⊕y is a divisor∗ of either x, y, or both. Here ⊕ is the bitwise XOR operator.∗The number b is a divisor of the number a if there exists an integer c such that a=b⋅c.

### Input
InputThe first line contains a single integer t (1≤t≤104) — the number of test cases.The first and only line of each test case contains two space-separated integers x and m (1≤x≤106, 1≤m≤1018).It is guaranteed that the sum of x over all test cases does not exceed 107.

### Output
OutputFor each test case, print a single integer — the number of suitable y.
NoteIn the first test case, for x=6, there are 3 valid values for y among the integers from 1 to m=9, and they are 4, 5, and 7.  y=4 is valid because x⊕y=6⊕4=2 and 2 is a divisor of both x=6 and y=4.  y=5 is valid because x⊕y=6⊕5=3 and 3 is a divisor of x=6.  y=7 is valid because x⊕y=6⊕7=1 and 1 is a divisor of both x=6 and y=7. In the second test case, for x=5, there are 2 valid values for y among the integers from 1 to m=7, and they are 4 and 6.  y=4 is valid because x⊕y=5⊕4=1 and 1 is a divisor of both x=5 and y=4.  y=6 is valid because x⊕y=5⊕6=3 and 3 is a divisor of y=6.
