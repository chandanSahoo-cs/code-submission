# [D. Divisible Pairs](https://codeforces.com/contest/1931/problem/D)

---
Polycarp has two favorite integers xx and yy (they can be equal), and he has found an array aa of length nn.Polycarp considers a pair of indices ⟨i,j⟩⟨i,j⟩ (1≤i<j≤n1≤i<j≤n) beautiful if:   ai+ajai+aj is divisible by xx;  ai−ajai−aj is divisible by yy. For example, if x=5x=5, y=2y=2, n=6n=6, a=a=[1,2,7,4,9,61,2,7,4,9,6], then the only beautiful pairs are:   ⟨1,5⟩⟨1,5⟩: a1+a5=1+9=10a1+a5=1+9=10 (1010 is divisible by 55) and a1−a5=1−9=−8a1−a5=1−9=−8 (−8−8 is divisible by 22);  ⟨4,6⟩⟨4,6⟩: a4+a6=4+6=10a4+a6=4+6=10 (1010 is divisible by 55) and a4−a6=4−6=−2a4−a6=4−6=−2 (−2−2 is divisible by 22).  Find the number of beautiful pairs in the array aa.

### Input
InputThe first line of the input contains a single integer tt (1≤t≤1041≤t≤104) — the number of test cases. Then the descriptions of the test cases follow.The first line of each test case contains three integers nn, xx, and yy (2≤n≤2⋅1052≤n≤2⋅105, 1≤x,y≤1091≤x,y≤109) — the size of the array and Polycarp's favorite integers.The second line of each test case contains nn integers a1,a2,…,ana1,a2,…,an (1≤ai≤1091≤ai≤109) — the elements of the array.It is guaranteed that the sum of nn over all test cases does not exceed 2⋅1052⋅105.

### Output
OutputFor each test case, output a single integer — the number of beautiful pairs in the array aa.
