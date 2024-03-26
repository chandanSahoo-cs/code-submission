# [B. Chaya Calendar](https://codeforces.com/contest/1932/problem/B)

---
The Chaya tribe believes that there are n signs of the apocalypse. Over time, it has been found out that the i-th sign occurs every ai years (in years ai, 2⋅ai, 3⋅ai, …).According to the legends, for the apocalypse to happen, the signs must occur sequentially. That is, first they wait for the first sign to occur, then strictly after it, the second sign will occur, and so on. That is, if the i-th sign occurred in the year x, the tribe starts waiting for the occurrence of the (i+1)-th sign, starting from the year x+1.In which year will the n-th sign occur and the apocalypse will happen?

### Input
InputThe first line of the input contains a single integer t (1≤t≤1000) — the number of test cases. Then follow the descriptions of the test cases.The first line of each test case contains a single integer n (1≤n≤100) — the number of signs.The second line of each test case contains n integers a1,a2,a3,…,an (1≤ai≤106) — the periodicities of the signs.

### Output
OutputFor each test case, output a single integer — the year in which all n signs will occur.
NoteIn the first set of input data of the example:  The tribe will wait for the first sign in the 3-rd year;  the tribe will wait for the second sign in the 4-th year (since year 2 have already passed);  the tribe will wait for the third sign in the 8-th year (since the second sign has already occurred in the 4-th year);  the tribe will wait for the fourth sign in the 10-th year (since year 5 have already passed);  the tribe will wait for the fifth sign in the 18-th year (since year 9 have already passed);  the tribe will wait for the sixth sign in the 36-th year (since the fifth sign has already occurred in the 18-th year).
