# [A. To Zero](https://codeforces.com/contest/2075/problem/A)

---
You are given two integers n and k; k is an odd number not less than 3. Your task is to turn n into 0.To do this, you can perform the following operation any number of times: choose a number x from 1 to k and subtract it from n. However, if the current value of n is even (divisible by 2), then x must also be even, and if the current value of n is odd (not divisible by 2), then x must be odd.In different operations, you can choose the same values of x, but you don't have to. So, there are no limitations on using the same value of x.Calculate the minimum number of operations required to turn n into 0.

### Input
InputThe first line contains one integer t (1≤t≤10000) — the number of test cases.Each test case consists of one line containing two integers n and k (3≤k≤n≤109, k is odd).

### Output
OutputFor each test case, output one integer — the minimum number of operations required to turn n into 0.
NoteIn the first example from the statement, you can first subtract 5 from 39 to get 34. Then subtract 6 five times to get 4. Finally, subtract 4 to get 0.In the second example, you can subtract 3 once, and then subtract 2 three times.In the third example, you can subtract 2 three times.
