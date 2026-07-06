# [D. Jumping Through Segments](https://codeforces.com/contest/1907/problem/D)

---
Polycarp is designing a level for a game. The level consists of n segments on the number line, where the i-th segment starts at the point with coordinate li and ends at the point with coordinate ri.The player starts the level at the point with coordinate 0. In one move, they can move to any point that is within a distance of no more than k. After their i-th move, the player must land within the i-th segment, that is, at a coordinate x such that li≤x≤ri. This means:  After the first move, they must be inside the first segment (from l1 to r1);  After the second move, they must be inside the second segment (from l2 to r2);  ...  After the n-th move, they must be inside the n-th segment (from ln to rn). The level is considered completed if the player reaches the n-th segment, following the rules described above. After some thought, Polycarp realized that it is impossible to complete the level with some values of k.Polycarp does not want the level to be too easy, so he asks you to determine the minimum integer k with which it is possible to complete the level.

### Input
InputThe first line contains a single integer t (1≤t≤104)—the number of test cases. Descriptions of the test cases follow.The first line of each test case contains a single integer n (1≤n≤2⋅105)—the number of segments in the level.The following n lines.The i-th line contain two integers li and ri (0≤li≤ri≤109)—the boundaries of the i-th segment. Segments may intersect.It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

### Output
OutputFor each test case, output a single integer—the minimum value of k with which it is possible to complete the level.
NoteIn the third example, the player can make the following moves:  Move from point 0 to point 5 (3≤5≤8);  Move from point 5 to point 10 (10≤10≤18);  Move from point 10 to point 7 (6≤7≤11). Note that for the last move, the player could have chosen not to move and still complete the level.
