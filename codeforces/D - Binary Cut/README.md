# [D. Binary Cut](https://codeforces.com/contest/1971/problem/D)

---
You are given a binary string†. Please find the minimum number of pieces you need to cut it into, so that the resulting pieces can be rearranged into a sorted binary string.  Note that:   each character must lie in exactly one of the pieces;  the pieces must be contiguous substrings of the original string;  you must use all the pieces in the rearrangement. † A binary string is a string consisting of characters 0 and 1. A sorted binary string is a binary string such that all characters 0 come before all characters 1.

### Input
InputThe first line contains a single integer t (1≤t≤500) — the number of test cases.The only line of each test case contains a single string s (1≤|s|≤500) consisting of characters 0 and 1, where |s| denotes the length of the string s.

### Output
OutputFor each test case, output a single integer — the minimum number of pieces needed to be able to rearrange the string into a sorted binary string.
NoteThe first test case is pictured in the statement. It can be proven that you can't use fewer than 3 pieces.In the second and third test cases, the binary string is already sorted, so only 1 piece is needed.In the fourth test case, you need to make a single cut between the two characters and rearrange them to make the string 01.
