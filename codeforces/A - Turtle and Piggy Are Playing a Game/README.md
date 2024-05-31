# [A. Turtle and Piggy Are Playing a Game](https://codeforces.com/contest/1981/problem/A)

---
Turtle and Piggy are playing a number game.First, Turtle will choose an integer x, such that l≤x≤r, where l,r are given. It's also guaranteed that 2l≤r.Then, Piggy will keep doing the following operation until x becomes 1:  Choose an integer p such that p≥2 and p∣x (i.e. x is a multiple of p).  Set x to xp, and the score will increase by 1. The score is initially 0. Both Turtle and Piggy want to maximize the score. Please help them to calculate the maximum score.

### Input
InputEach test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows.The first line of each test case contains two integers l,r (1≤l≤r≤109,2l≤r) — The range where Turtle can choose the integer from.

### Output
OutputFor each test case, output a single integer — the maximum score.
NoteIn the first test case, Turtle can choose an integer x, such that 2≤x≤4. He can choose x=4. Then Piggy can choose p=2 for 2 times. After that, x will become 1, and the score will be 2, which is maximized.In the second test case, Turtle can choose an integer 3≤x≤6. He can choose x=6. Then Piggy can choose p=2, then choose p=3. After that, x will become 1, and the score will be 2, which is maximum.In the third test case, Turtle can choose x=12.In the fourth test case, Turtle can choose x=16.
