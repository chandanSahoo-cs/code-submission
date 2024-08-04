# [A. Question Marks](https://codeforces.com/contest/1993/problem/A)

---
Tim is doing a test consisting of 4n4n questions; each question has 44 options: 'A', 'B', 'C', and 'D'. For each option, there are exactly nn correct answers corresponding to that option — meaning there are nn questions with the answer 'A', nn questions with the answer 'B', nn questions with the answer 'C', and nn questions with the answer 'D'.For each question, Tim wrote his answer on the answer sheet. If he could not figure out the answer, he would leave a question mark '?' for that question.You are given his answer sheet of 4n4n characters. What is the maximum number of correct answers Tim can get?

### Input
InputThe first line contains a single integer tt (1≤t≤10001≤t≤1000) — the number of test cases.The first line of each test case contains an integer nn (1≤n≤1001≤n≤100).The second line of each test case contains a string ss of 4n4n characters (si∈{A,B,C,D,?}si∈{A,B,C,D,?}) — Tim's answers for the questions.

### Output
OutputFor each test case, print a single integer — the maximum score that Tim can achieve.
NoteIn the first test case, there is exactly one question with each answer 'A', 'B', 'C', and 'D'; so it's possible that Tim gets all his answers correct.In the second test case, there are only two correct answers 'A' which makes him get exactly 22 points in any case.In the third test case, Tim can get at most 22 correct answers with option 'A' and 22 correct answers with option 'B'. For example, he would get 44 points if the answers were 'AACCBBDD'.In the fourth test case, he refuses to answer any question at all, which makes him get 00 points.
