# [B. Vicious Labyrinth](https://codeforces.com/contest/2078/problem/B)

---
Axium Crisis - ak+q There are nn cells in a labyrinth, and cell ii (1≤i≤n1≤i≤n) is n−in−i kilometers away from the exit. In particular, cell nn is the exit. Note also that each cell is connected to the exit but is not accessible from any other cell in any way.In each cell, there is initially exactly one person stuck in it. You want to help everyone get as close to the exit as possible by installing a teleporter in each cell ii (1≤i≤n1≤i≤n), which translocates the person in that cell to another cell aiai.The labyrinth owner caught you in the act. Amused, she let you continue, but under some conditions: Everyone must use the teleporter exactly kk times. No teleporter in any cell can lead to the same cell it is in. Formally, i≠aii≠ai for all 1≤i≤n1≤i≤n.You must find a teleporter configuration that minimizes the sum of distances of all individuals from the exit after using the teleporter exactly kk times while still satisfying the restrictions of the labyrinth owner.If there are many possible configurations, you can output any of them.

### Input
InputEach test contains multiple test cases. The first line contains the number of test cases tt (1≤t≤1041≤t≤104). The description of the test cases follows. The first and only line of each test case contains two integers nn and kk (2≤n≤2⋅1052≤n≤2⋅105, 1≤k≤1091≤k≤109) — the number of cells in the labyrinth and the value kk.It is guaranteed that the total sum of nn across all test cases does not exceed 2⋅1052⋅105.

### Output
OutputFor each test case, output nn integers — the destinations of the teleporters a1,a2,…,ana1,a2,…,an in order, satisfying the given conditions (1≤ai≤n1≤ai≤n, ai≠iai≠i).
NoteIn the first test case, the position of each person is as follows. Before teleporting: [1,2][1,2]. First teleportation: [2,1][2,1].The distance sum is (2−2)+(2−1)=1(2−2)+(2−1)=1, which is the minimum possible.In the second test case, the position of each person is as follows. Before teleporting: [1,2,3]. First teleportation: [2,3,2]. Second teleportation: [3,2,3].The distance sum is (3−3)+(3−2)+(3−3)=1, which is the minimum possible.
