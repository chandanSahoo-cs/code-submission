# [C. Turtle Fingers: Count the Values of k](https://codeforces.com/contest/1933/problem/C)

---
You are given three positive integers a, b and l (a,b,l>0). It can be shown that there always exists a way to choose non-negative (i.e. ≥0) integers k, x, and y such that l=k⋅ax⋅by. Your task is to find the number of distinct possible values of k across all such ways.

### Input
InputThe first line contains the integer t (1≤t≤104) — the number of test cases.The following t lines contain three integers, a, b and l (2≤a,b≤100, 1≤l≤106) — description of a test case.

### Output
OutputOutput t lines, with the i-th (1≤i≤t) line containing an integer, the answer to the i-th test case.
NoteIn the first test case, a=2,b=5,l=20. The possible values of k (and corresponding x,y) are as follows:   Choose k=1,x=2,y=1. Then k⋅ax⋅by=1⋅22⋅51=20=l.  Choose k=2,x=1,y=1. Then k⋅ax⋅by=2⋅21⋅51=20=l.  Choose k=4,x=0,y=1. Then k⋅ax⋅by=4⋅20⋅51=20=l.  Choose k=5,x=2,y=0. Then k⋅ax⋅by=5⋅22⋅50=20=l.  Choose k=10,x=1,y=0. Then k⋅ax⋅by=10⋅21⋅50=20=l.  Choose k=20,x=0,y=0. Then k⋅ax⋅by=20⋅20⋅50=20=l. In the second test case, a=2,b=5,l=21. Note that l=21 is not divisible by either a=2 or b=5. Therefore, we can only set x=0,y=0, which corresponds to k=21.In the third test case, a=4,b=6,l=48. The possible values of k (and corresponding x,y) are as follows:   Choose k=2,x=1,y=1. Then k⋅ax⋅by=2⋅41⋅61=48=l.  Choose k=3,x=2,y=0. Then k⋅ax⋅by=3⋅42⋅60=48=l.  Choose k=8,x=0,y=1. Then k⋅ax⋅by=8⋅40⋅61=48=l.  Choose k=12,x=1,y=0. Then k⋅ax⋅by=12⋅41⋅60=48=l.  Choose k=48,x=0,y=0. Then k⋅ax⋅by=48⋅40⋅60=48=l.
