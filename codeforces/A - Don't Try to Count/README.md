# [A. Don't Try to Count](https://codeforces.com/contest/1881/problem/A)

---
Given a string x of length n and a string s of length m (n⋅m≤25), consisting of lowercase Latin letters, you can apply any number of operations to the string x.In one operation, you append the current value of x to the end of the string x. Note that the value of x will change after this.For example, if x="aba", then after applying operations, x will change as follows: "aba" → "abaaba" → "abaabaabaaba".After what minimum number of operations s will appear in x as a substring? A substring of a string is defined as a contiguous segment of it.

### Input
InputThe first line of the input contains a single integer t (1≤t≤104) — the number of test cases.The first line of each test case contains two numbers n and m (1≤n⋅m≤25) — the lengths of strings x and s, respectively.The second line of each test case contains the string x of length n.The third line of each test case contains the string s of length m.

### Output
OutputFor each test case, output a single number — the minimum number of operations after which s will appear in x as a substring. If this is not possible, output −1.
NoteIn the first test case of the example, after 2 operations, the string will become "aaaa", and after 3 operations, it will become "aaaaaaaa", so the answer is 3.In the second test case of the example, after applying 1 operation, the string will become "eforceforc", where the substring is highlighted in red.In the fourth test case of the example, it can be shown that it is impossible to obtain the desired string as a substring.
