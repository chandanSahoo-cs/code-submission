# [A. Kevin and Arithmetic](https://codeforces.com/contest/2061/problem/A)

---
To train young Kevin's arithmetic skills, his mother devised the following problem.Given n integers a1,a2,…,an and a sum s initialized to 0, Kevin performs the following operation for i=1,2,…,n in order:   Add ai to s. If the resulting s is even, Kevin earns a point and repeatedly divides s by 2 until it becomes odd. Note that Kevin can earn at most one point per operation, regardless of how many divisions he does.Since these divisions are considered more beneficial for Kevin's development, his mother wants to rearrange a so that the number of Kevin's total points is maximized. Determine the maximum number of points.

### Input
InputEach test contains multiple test cases. The first line contains the number of test cases t (1≤t≤500). The description of the test cases follows. The first line of each test case contains a single integer n (1≤n≤100) — the number of integers.The second line contains n integers a1,a2,…,an (1≤ai≤109).

### Output
OutputFor each test case, output one integer — the maximum number of points.
NoteIn the first test case, the only arrangement of a is [1]. s becomes 1. Kevin earns no points.In the second test case, the only possible arrangement of a is [2,1]. s becomes 1 and 1 successively. Kevin earns points in both operations.In the third test case, one possible arrangement of a is [2,4,6]. s becomes 1, 5, and 11 successively. Kevin earns a point in the first operation.
