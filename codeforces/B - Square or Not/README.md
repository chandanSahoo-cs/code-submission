# [B. Square or Not](https://codeforces.com/contest/2008/problem/B)

---
A beautiful binary matrix is a matrix that has ones on its edges and zeros inside.  Examples of four beautiful binary matrices. Today, Sakurako was playing with a beautiful binary matrix of size r×c and created a binary string s by writing down all the rows of the matrix, starting from the first and ending with the r-th. More formally, the element from the matrix in the i-th row and j-th column corresponds to the ((i−1)∗c+j)-th element of the string.You need to check whether the beautiful matrix from which the string s was obtained could be squared. In other words, you need to check whether the string s could have been build from a square beautiful binary matrix (i.e., one where r=c).

### Input
InputThe first line contains a single integer t (1≤t≤104) — the number of test cases.The first line of each test case contains a single integer n (2≤n≤2⋅105) — the length of the string.The second line of each test case contains the string s of length n. The string is always the result of writing out the strings of a beautiful matrix.It is guaranteed that the sum of n across all test cases does not exceed 2⋅105.

### Output
OutputPrint "Yes", if the original matrix could have been square, and "No" otherwise.
NoteFor the second test case, string 1111 can be obtained from the matrix: 1111 For the third test case, string 111101111 can be obtained from the matrix: 111101111 There is no square matrix in the fourth case, such that the string can be obtained from it.
