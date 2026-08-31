# [C2. Marenol (hard version)](https://codeforces.com/contest/2254/problem/C2)

---
This is the hard version of the problem. In this version, you are asked to determine the minimum number of operations to transform a into b.Yousef has given you two binary strings, a and b, of the same length n.You are allowed to perform any of the following operations:   Choose a substring∗ in a equal to 001 and replace it with 100, or vice versa (i.e. 001→100 or 100→001).  Choose a substring in a equal to 110 and replace it with 011, or vice versa (i.e. 011→110 or 110→011). Your task is to determine the minimum number of operations required to transform string a into string b. If it is impossible to transform a into b using the given operations, output −1 instead.∗A string a is a substring of a string b if a can be obtained from b by deletion of several (possibly zero or all) characters from the beginning and several (possibly zero or all) characters from the end.

### Input
InputThe first line contains a single integer t (1≤t≤104) — the number of test cases.The first line of each test case contains a single integer n (1≤n≤2⋅105) — the length of each string.The second line of each test case contains a binary string a (|a|=n), consisting of only characters 0 and/or 1.The third line of each test case contains a binary string b (|b|=n), consisting of only characters 0 and/or 1.It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

### Output
OutputFor each test case, output the minimum number of operations required to transform a into b. If it is impossible, output −1 instead.
NoteIn the first test case, we can choose the substring a[2,4]=100 and replace it with 001. This takes exactly 1 operation.In the second test case, it is impossible to transform a into b, so the answer is −1.In the third test case, we can do the following in order:  110000 → 100100  100100 → 100001  100001 → 001001  001001 → 000011 This takes 4 operations. It can be shown that 4 is the minimum answer.
