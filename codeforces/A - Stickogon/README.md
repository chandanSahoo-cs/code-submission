# [A. Stickogon](https://codeforces.com/contest/1957/problem/A)

---
You are given n sticks of lengths a1,a2,…,an. Find the maximum number of regular (equal-sided) polygons you can construct simultaneously, such that:   Each side of a polygon is formed by exactly one stick.  No stick is used in more than 1 polygon. Note: Sticks cannot be broken.

### Input
InputThe first line contains a single integer t (1≤t≤100) — the number of test cases.The first line of each test case contains a single integer n (1≤n≤100) — the number of sticks available.The second line of each test case contains n integers a1,a2,…,an (1≤ai≤100) — the stick lengths.

### Output
OutputFor each test case, output a single integer on a new line — the maximum number of regular (equal-sided) polygons you can make simultaneously from the sticks available.
NoteIn the first test case, we only have one stick, hence we can't form any polygon.In the second test case, the two sticks aren't enough to form a polygon either.In the third test case, we can use the 4 sticks of length 3 to create a square.In the fourth test case, we can make a pentagon with side length 2, and a square of side length 4.
