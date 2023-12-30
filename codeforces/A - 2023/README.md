# [A. 2023](https://codeforces.com/contest/1916/problem/A)

---
In a sequence a, whose product was equal to 2023, k numbers were removed, leaving a sequence b of length n. Given the resulting sequence b, find any suitable sequence a and output which k elements were removed from it, or state that such a sequence could not have existed.Notice that you are not guaranteed that such array exists.

### Input
InputEach test consists of several test cases. The first line contains a single integer t (1≤t≤100) — the number of test cases. This is followed by a description of the test cases.The first line of each test case contains two integers n (1≤n,k≤5) — the size of sequence b and the number of numbers removed from sequence a.The second line contains n integers b1,b2,…,bn (1≤bi≤2023) — the remaining sequence. The values of bi might not be divisors of 2023.

### Output
OutputFor each test case, output "YES" if the sequence a exists, and in the following line output k non-negative integers that were removed from the sequence a. If the sequence a does not exist, output "NO" in a single line.You can output the answer in any case (uppercase or lowercase). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive answers.
NoteIn third test case product is equal to 289⋅7=2023.In fourth test case product is already equal to 2023.In seventh test case product is equal to 7⋅17⋅17=2023.
