# [A. Insert Digit](https://codeforces.com/contest/1811/problem/A)

---
You have a positive number of length n and one additional digit.You can insert this digit anywhere in the number, including at the beginning or at the end.Your task is to make the result as large as possible.For example, you have the number 76543, and the additional digit is 4. Then the maximum number you can get is 765443, and it can be obtained in two ways — by inserting a digit after the 3th or after the 4th digit of the number.

### Input
InputThe first line contains a single integer t (1≤t≤104) — the number of test cases.The descriptions of the test cases follow.The first line of the description of each test case contains two integers n and d (1≤n≤2⋅105; 0≤d≤9) — the length of the number and an additional digit, respectively.The second line of the description of each test case contains a string consisting of n digits — the number that you have initially. It is guaranteed that the number does not contain leading zeros.It is guaranteed that the sum of n for all test cases does not exceed 2⋅105.

### Output
OutputFor each test case, output a string consisting of n+1 digits — the maximum possible number that can be obtained.
