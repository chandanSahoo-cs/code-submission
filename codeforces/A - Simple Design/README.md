# [A. Simple Design](https://codeforces.com/contest/1884/problem/A)

---
A positive integer is called k-beautiful, if the digit sum of the decimal representation of this number is divisible by k†. For example, 9272 is 5-beautiful, since the digit sum of 9272 is 9+2+7+2=20.You are given two integers x and k. Please find the smallest integer y≥x which is k-beautiful.† An integer n is divisible by k if there exists an integer m such that n=k⋅m.

### Input
InputEach test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows.The only line of each test case contains two integers x and k (1≤x≤109, 1≤k≤10).

### Output
OutputFor each test case, output the smallest integer y≥x which is k-beautiful.
NoteIn the first test case, numbers from 1 to 4 consist of a single digit, thus the digit sum is equal to the number itself. None of the integers from 1 to 4 are divisible by 5.In the fourth test case, the digit sum of 777 is 7+7+7=21 which is already divisible by 3.
