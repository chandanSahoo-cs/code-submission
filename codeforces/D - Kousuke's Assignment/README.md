# [D. Kousuke's Assignment](https://codeforces.com/contest/2033/problem/D)

---
After a trip with Sakurako, Kousuke was very scared because he forgot about his programming assignment. In this assignment, the teacher gave him an array a of n integers and asked him to calculate the number of non-overlapping segments of the array a, such that each segment is considered beautiful.A segment [l,r] is considered beautiful if al+al+1+⋯+ar−1+ar=0.For a fixed array a, your task is to compute the maximum number of non-overlapping beautiful segments.

### Input
InputThe first line of input contains the number t (1≤t≤104) — the number of test cases. Each test case consists of 2 lines.   The first line contains one integer n (1≤n≤105) — the length of the array. The second line contains n integers ai (−105≤ai≤105) — the elements of the array a. It is guaranteed that the sum of n across all test cases does not exceed 3⋅105.

### Output
OutputFor each test case, output a single integer: the maximum number of non-overlapping beautiful segments.
