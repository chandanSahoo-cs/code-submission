# [C. Berland Regional](https://codeforces.com/contest/1519/problem/C)

---
Polycarp is an organizer of a Berland ICPC regional event. There are n universities in Berland numbered from 1 to n. Polycarp knows all competitive programmers in the region. There are n students: the i-th student is enrolled at a university ui and has a programming skill si.Polycarp has to decide on the rules now. In particular, the number of members in the team.Polycarp knows that if he chooses the size of the team to be some integer k, each university will send their k strongest (with the highest programming skill s) students in the first team, the next k strongest students in the second team and so on. If there are fewer than k students left, then the team can't be formed. Note that there might be universities that send zero teams.The strength of the region is the total skill of the members of all present teams. If there are no teams present, then the strength is 0.Help Polycarp to find the strength of the region for each choice of k from 1 to n.

### Input
InputThe first line contains a single integer t (1≤t≤1000) — the number of testcases.The first line of each testcase contains a single integer n (1≤n≤2⋅105) — the number of universities and the number of students.The second line of each testcase contains n integers u1,u2,…,un (1≤ui≤n) — the university the i-th student is enrolled at.The third line of each testcase contains n integers s1,s2,…,sn (1≤si≤109) — the programming skill of the i-th student.The sum of n over all testcases doesn't exceed 2⋅105.

### Output
OutputFor each testcase print n integers: the strength of the region — the total skill of the members of the present teams — for each choice of team size k.
NoteIn the first testcase the teams from each university for each k are:   k=1:   university 1: [6],[5],[5],[3];  university 2: [8],[1],[1];   k=2:   university 1: [6,5],[5,3];  university 2: [8,1];   k=3:   university 1: [6,5,5];  university 2: [8,1,1];   k=4:   university 1: [6,5,5,3];
