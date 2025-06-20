# [D. Divide and Equalize](https://codeforces.com/contest/1881/problem/D)

---
You are given an array a consisting of n positive integers. You can perform the following operation on it:   Choose a pair of elements ai and aj (1≤i,j≤n and i≠j);  Choose one of the divisors of the integer ai, i.e., an integer x such that aimodx=0;  Replace ai with aix and aj with aj⋅x.  Determine whether it is possible to make all elements in the array the same by applying the operation a certain number of times (possibly zero).For example, let's consider the array a = [100,2,50,10,1] with 5 elements. Perform two operations on it:   Choose a3=50 and a2=2, x=5. Replace a3 with a3x=505=10, and a2 with a2⋅x=2⋅5=10. The resulting array is a = [100,10,10,10,1];  Choose a1=100 and a5=1, x=10. Replace a1 with a1x=10010=10, and a5 with a5⋅x=1⋅10=10. The resulting array is a = [10,10,10,10,10].  After performing these operations, all elements in the array a become equal to 10.

### Input
InputThe first line of the input contains a single integer t (1≤t≤2000) — the number of test cases.Then follows the description of each test case.The first line of each test case contains a single integer n (1≤n≤104) — the number of elements in the array a.The second line of each test case contains exactly n integers ai (1≤ai≤106) — the elements of the array a.It is guaranteed that the sum of n over all test cases does not exceed 104.

### Output
OutputFor each test case, output a single line:   "YES" if it is possible to make all elements in the array equal by applying the operation a certain (possibly zero) number of times;  "NO" otherwise. You can output the answer in any case (for example, the strings "yEs", "yes", "Yes", and "YES" will all be recognized as a positive answer).
NoteThe first test case is explained in the problem statement.
