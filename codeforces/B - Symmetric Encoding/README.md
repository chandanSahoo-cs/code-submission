# [B. Symmetric Encoding](https://codeforces.com/contest/1974/problem/B)

---
Polycarp has a string ss, which consists of lowercase Latin letters. He encodes this string using the following algorithm:  first, he constructs a new auxiliary string rr, which consists of all distinct letters of the string ss, written in alphabetical order;  then the encoding happens as follows: each character in the string ss is replaced by its symmetric character from the string rr (the first character of the string rr will be replaced by the last, the second by the second from the end, and so on). For example, encoding the string ss="codeforces" happens as follows:  the string rr is obtained as "cdefors";  the first character s1s1='c' is replaced by 's';  the second character s2s2='o' is replaced by 'e';  the third character s3s3='d' is replaced by 'r';  ...  the last character s10s10='s' is replaced by 'c'.   The string rr and replacements for ss="codeforces". Thus, the result of encoding the string ss="codeforces" is the string "serofedsoc".Write a program that performs decoding — that is, restores the original string ss from the encoding result.

### Input
InputThe first line contains a single integer tt (1≤t≤1041≤t≤104) — the number of test cases.The first line of each test case contains a single integer nn (1≤n≤2⋅1051≤n≤2⋅105) — the length of the string bb.The second line of each test case contains a string bb of length nn, consisting of lowercase Latin letters — the result of encoding the original string ss.It is guaranteed that the sum of the values of nn over all test cases in the test does not exceed 2⋅1052⋅105.

### Output
OutputFor each test case, output the string ss from which the encoding result bb was obtained.
