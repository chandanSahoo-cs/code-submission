# [D. Strong Vertices](https://codeforces.com/contest/1857/problem/D)

---
Given two arrays aa and bb, both of length nn. Elements of both arrays indexed from 11 to nn. You are constructing a directed graph, where edge from uu to vv (u≠vu≠v) exists if au−av≥bu−bvau−av≥bu−bv.A vertex VV is called strong if there exists a path from VV to all other vertices.A path in a directed graph is a chain of several vertices, connected by edges, such that moving from the vertex uu, along the directions of the edges, the vertex vv can be reached.Your task is to find all strong vertices.For example, if a=[3,1,2,4]a=[3,1,2,4] and b=[4,3,2,1]b=[4,3,2,1], the graph will look like this:   The graph has only one strong vertex with number 44

### Input
InputThe first line contains an integer tt (1≤t≤1041≤t≤104) — the number of test cases.The first line of each test case contains an integer nn (2≤n≤2⋅1052≤n≤2⋅105) — the length of aa and bb.The second line of each test case contains nn integers a1,a2…ana1,a2…an (−109≤ai≤109−109≤ai≤109) — the array aa.The third line of each test case contains nn integers b1,b2…bnb1,b2…bn (−109≤bi≤109−109≤bi≤109) — the array bb.It is guaranteed that the sum of nn for all test cases does not exceed 2⋅1052⋅105.

### Output
OutputFor each test case, output two lines: in the first line, output the number of strong vertices, and in the second line, output all strong vertices in ascending order.
NoteThe first sample is covered in the problem statement.For the second sample, the graph looks like this:   The graph has two strong vertices with numbers 33 and 55. Note that there is a bidirectional edge between vertices 33 and 55. In the third sample, the vertices are connected by a single directed edge from vertex 22 to vertex 11, so the only strong vertex is 22.In the fourth sample, all vertices are connected to each other by bidirectional edges, so there is a path from every vertex to any other vertex.
