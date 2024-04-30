# [B. Shifts and Sorting](https://codeforces.com/contest/1969/problem/B)

---
Let's define a cyclic shift of some string s as a transformation from s1s2…sn−1sn into sns1s2…sn−1. In other words, you take one last character sn and place it before the first character while moving all other characters to the right.You are given a binary string s (a string consisting of only 0-s and/or 1-s).In one operation, you can choose any substring slsl+1…sr (1≤l<r≤|s|) and cyclically shift it. The cost of such operation is equal to r−l+1 (or the length of the chosen substring).You can perform the given operation any number of times. What is the minimum total cost to make s sorted in non-descending order?

### Input
InputThe first line contains a single integer t (1≤t≤104) — the number of test cases.The first and only line of each test case contains a binary string s (2≤|s|≤2⋅105; si∈ {0, 1}) — the string you need to sort.Additional constraint on the input: the sum of lengths of strings over all test cases doesn't exceed 2⋅105.

### Output
OutputFor each test case, print the single integer — the minimum total cost to make string sorted using operation above any number of times.
NoteIn the first test case, you can choose the whole string and perform a cyclic shift: 10 → 01. The length of the substring is 2, so the cost is 2.In the second test case, the string is already sorted, so you don't need to perform any operations.In the third test case, one of the optimal strategies is the next:   choose substring [1,3]: 11000 → 01100;  choose substring [2,4]: 01100 → 00110;  choose substring [3,5]: 00110 → 00011.  The total cost is 3+3+3=9.
