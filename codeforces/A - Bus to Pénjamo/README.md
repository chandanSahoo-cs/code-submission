# [A. Bus to Pénjamo](https://codeforces.com/contest/2022/problem/A)

---
Ya vamos llegando a Péeeenjamoo ♫♫♫  There are n families travelling to Pénjamo to witness Mexico's largest-ever "walking a chicken on a leash" marathon. The i-th family has ai family members. All families will travel using a single bus consisting of r rows with 2 seats each.A person is considered happy if:   Another family member is seated in the same row as them, or  They are sitting alone in their row (with an empty seat next to them). Determine the maximum number of happy people in an optimal seating arrangement. Note that everyone must be seated in the bus.It is guaranteed that all family members will fit on the bus. Formally, it is guaranteed that n∑i=1ai≤2r.

### Input
InputEach test contains multiple test cases. The first line contains the number of test cases t (1≤t≤1000). The description of the test cases follows.The first line of each test case contains two integers n and r (1≤n≤100; 1≤r≤500) — the number of families and the number of rows in the bus.The second line contains n integers a1,a2,…,an (1≤ai≤10) — the number of family members in each family.

### Output
OutputFor each test case, output the maximum number of happy people in an optimal seating arrangement.
NoteIn the first test case, the two members of the first family can sit together in the first row, while the two members of the second family can sit together in the second row. The remaining member of the second family can sit in the third row along with a member of the third family. This seating arrangement is shown below, where the 4 happy people are colored green. 112223 In the second test case, a possible seating arrangement with 6 happy people is shown below. 331122 In the third test case, a possible seating arrangement with 6 happy people is shown below. 442331
