# [C. Showering](https://codeforces.com/contest/1999/problem/C)

---
As a computer science student, Alex faces a hard challenge — showering. He tries to shower daily, but despite his best efforts there are always challenges. He takes ss minutes to shower and a day only has mm minutes! He already has nn tasks planned for the day. Task ii is represented as an interval (li(li, ri)ri), which means that Alex is busy and can not take a shower in that time interval (at any point in time strictly between lili and riri). No two tasks overlap.Given all nn time intervals, will Alex be able to shower that day? In other words, will Alex have a free time interval of length at least ss? In the first test case, Alex can shower for the first 33 minutes of the day and not miss any of the tasks.

### Input
InputThe first line contains a single integer tt (1≤t≤1041≤t≤104) — the number of test cases.The first line of each test case contains three integers nn, ss, and mm (1≤n≤2⋅1051≤n≤2⋅105; 1≤s,m≤1091≤s,m≤109) — the number of time intervals Alex already has planned, the amount of time Alex takes to take a shower, and the amount of minutes a day has.Then nn lines follow, the ii-th of which contains two integers lili and riri (0≤li<ri≤m0≤li<ri≤m) — the time interval of the ii-th task. No two tasks overlap.Additional constraint on the input: li>ri−1li>ri−1 for every i>1i>1.The sum of nn over all test cases does not exceed 2⋅1052⋅105.

### Output
OutputFor each test case output "YES" (without quotes) if Alex can take a shower for that given test case, and "NO" (also without quotes) otherwise.You can output "YES" and "NO" in any case (for example, strings "yEs", "yes", and "Yes" will be recognized as a positive response).
