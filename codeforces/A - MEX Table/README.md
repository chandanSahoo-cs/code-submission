# [A. MEX Table](https://codeforces.com/contest/2057/problem/A)

---
One day, the schoolboy Mark misbehaved, so the teacher Sasha called him to the whiteboard.Sasha gave Mark a table with n rows and m columns. His task is to arrange the numbers 0,1,…,n⋅m−1 in the table (each number must be used exactly once) in such a way as to maximize the sum of MEX∗ across all rows and columns. More formally, he needs to maximize n∑i=1mex({ai,1,ai,2,…,ai,m})+m∑j=1mex({a1,j,a2,j,…,an,j}), where ai,j is the number in the i-th row and j-th column.Sasha is not interested in how Mark arranges the numbers, so he only asks him to state one number — the maximum sum of MEX across all rows and columns that can be achieved.∗The minimum excluded (MEX) of a collection of integers c1,c2,…,ck is defined as the smallest non-negative integer x which does not occur in the collection c. For example:   mex([2,2,1])=0, since 0 does not belong to the array.  mex([3,1,0,1])=2, since 0 and 1 belong to the array, but 2 does not.  mex([0,3,1,2])=4, since 0, 1, 2, and 3 belong to the array, but 4 does not.

### Input
InputEach test contains multiple test cases. The first line contains a single integer t (1≤t≤1000) — the number of test cases. The description of the test cases follows.The first line of each test case contains two integers n and m (1≤n,m≤109) — the number of rows and columns in the table, respectively.

### Output
OutputFor each test case, output the maximum possible sum of mex across all rows and columns.
NoteIn the first test case, the only element is 0, and the sum of the mex of the numbers in the first row and the mex of the numbers in the first column is mex({0})+mex({0})=1+1=2.In the second test case, the optimal table may look as follows:3021Then n∑i=1mex({ai,1,ai,2,…,ai,m})+m∑j=1mex({a1,j,a2,j,…,an,j})=mex({3,0})+mex({2,1}) +mex({3,2})+mex({0,1})=1+0+0+2=3.
