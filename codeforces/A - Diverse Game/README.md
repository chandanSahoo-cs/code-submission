# [A. Diverse Game](https://codeforces.com/contest/1994/problem/A)

---
Petr, watching Sergey's stream, came up with a matrix a, consisting of n rows and m columns (the number in the i-th row and j-th column is denoted as ai,j), which contains all integers from 1 to n⋅m. But he didn't like the arrangement of the numbers, and now he wants to come up with a new matrix b, consisting of n rows and m columns, which will also contain all integers from 1 to n⋅m, such that for any 1≤i≤n,1≤j≤m it holds that ai,j≠bi,j.You are given the matrix a, construct any matrix b that meets Petr's requirements, or determine that it is impossible.Hurry up! Otherwise, he will donate all his money to the stream in search of an answer to his question.

### Input
InputEach test consists of multiple test cases. The first line contains an integer t (1≤t≤103) — the number of test cases. Then follows the description of the test cases.The first line of each test case contains two integers n and m (1≤n,m≤10) — the number of rows and columns of matrix a.The next n lines contain m integers each, describing matrix a. The i-th of these lines contains the elements of matrix ai,1,ai,2,…,ai,m.It is guaranteed that all numbers in matrix a are distinct and 1≤ai,j≤n⋅m.It is guaranteed that the sum of n⋅m over all test cases does not exceed 5⋅104.

### Output
OutputFor each test case, output n⋅m integers — any suitable matrix b, or −1 if such a matrix does not exist.
NoteIn the first test case, there is only one element in the matrix, so matrix b is the only matrix and it does not fit.In the second test case a1,1=2≠1=b1,1, a2,1=1≠2=b2,1.
