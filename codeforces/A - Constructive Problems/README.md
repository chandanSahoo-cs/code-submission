# [A. Constructive Problems](https://codeforces.com/contest/1905/problem/A)

---
Gridlandia has been hit by flooding and now has to reconstruct all of it's cities. Gridlandia can be described by an n×mn×m matrix.Initially, all of its cities are in economic collapse. The government can choose to rebuild certain cities. Additionally, any collapsed city which has at least one vertically neighboring rebuilt city and at least one horizontally neighboring rebuilt city can ask for aid from them and become rebuilt without help from the government. More formally, collapsed city positioned in (i,j)(i,j) can become rebuilt if both of the following conditions are satisfied:  At least one of cities with positions (i+1,j)(i+1,j) and (i−1,j)(i−1,j) is rebuilt;  At least one of cities with positions (i,j+1)(i,j+1) and (i,j−1)(i,j−1) is rebuilt. If the city is located on the border of the matrix and has only one horizontally or vertically neighbouring city, then we consider only that city.   Illustration of two possible ways cities can be rebuilt by adjacent aid. White cells are collapsed cities, yellow cells are initially rebuilt cities (either by the government or adjacent aid), and orange cells are rebuilt cities after adjacent aid. The government wants to know the minimum number of cities it has to rebuild such that after some time all the cities can be rebuild.

### Input
InputEach test consists of multiple test cases. The first line contains a single integer tt (1≤t≤1041≤t≤104) — the number of test cases. The description of the test cases follows.The only line of each test case contains two integers nn and mm (2≤n,m≤1002≤n,m≤100) — the sizes of Gridlandia.

### Output
OutputFor each test case, output a single integer — the minimum number of cities the government needs to rebuild.
NoteIn the first test case, it's enough for the government to rebuild cities (1,2)(1,2) and (2,1)(2,1).In the second test case, it's enough for the government to rebuild cities (1,4)(1,4), (2,2)(2,2), (3,1)(3,1), (3,6)(3,6), (4,3)(4,3), (5,5)(5,5), (5,7)(5,7).
