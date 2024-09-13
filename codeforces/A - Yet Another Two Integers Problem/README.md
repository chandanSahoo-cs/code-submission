# [A. Yet Another Two Integers Problem](https://codeforces.com/contest/1409/problem/A)

---
You are given two integers a and b.In one move, you can choose some integer k from 1 to 10 and add it to a or subtract it from a. In other words, you choose an integer k∈[1;10] and perform a:=a+k or a:=a−k. You may use different values of k in different moves.Your task is to find the minimum number of moves required to obtain b from a.You have to answer t independent test cases.

### Input
InputThe first line of the input contains one integer t (1≤t≤2⋅104) — the number of test cases. Then t test cases follow.The only line of the test case contains two integers a and b (1≤a,b≤109).

### Output
OutputFor each test case, print the answer: the minimum number of moves required to obtain b from a.
NoteIn the first test case of the example, you don't need to do anything.In the second test case of the example, the following sequence of moves can be applied: 13→23→32→42 (add 10, add 9, add 10).In the third test case of the example, the following sequence of moves can be applied: 18→10→4 (subtract 8, subtract 6).
