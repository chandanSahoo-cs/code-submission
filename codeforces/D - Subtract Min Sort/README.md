# [D. Subtract Min Sort](https://codeforces.com/contest/2060/problem/D)

---
You are given a sequence a consisting of n positive integers.You can perform the following operation any number of times.  Select an index i (1≤i<n), and subtract min(ai,ai+1) from both ai and ai+1. Determine if it is possible to make the sequence non-decreasing by using the operation any number of times.

### Input
InputEach test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows.The first line of each test case contains a single integer n (2≤n≤2⋅105).The second line of each test case contains a1,a2,…,an (1≤ai≤109).It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

### Output
OutputIf it is possible to make the sequence non-decreasing, print "YES" on a new line. Otherwise, print "NO" on a new line.You can output the answer in any case. For example, the strings "yEs", "yes", and "Yes" will also be recognized as positive responses.
NoteIn the first test case, the array is already sorted.In the second test case, we can show that it is impossible.In the third test case, after performing an operation on i=1, the array becomes [0,1,2,3], which is now in nondecreasing order.
