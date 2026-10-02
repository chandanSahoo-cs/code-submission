# [D. Chikki Rules](https://codeforces.com/gym/720455/problem/D)

---
By the afternoon the whole coach is sharing food. There are nn passengers, and the i-th holds ai packets of chikki. Hitman has one rule: in one move a single packet passes from a passenger i to a different passenger j, and only if i currently has strictly more packets than j.Shanky wants the amounts, taken as a multiset, to become exactly b1,b2,…,bn; it does not matter who ends up with which amount. Formally, the goal is reached when there is a permutation π of {1,2,…,n} such that passenger π(k) has exactly bk packets for every k.Find the minimum number of moves needed to reach the goal, or report that it is impossible.

### Input
InputThe first line contains an integer T (1≤T≤104) — the number of test cases. The test cases follow.The first line of each test case contains an integer n (1≤n≤2⋅105).The second line contains n integers a1,a2,…,an (0≤ai≤109) — the current amounts.The third line contains n integers b1,b2,…,bn (0≤bi≤109) — the desired amounts.It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

### Output
OutputFor each test case print one integer — the minimum number of moves, or −1 if the goal cannot be reached.
NoteIn the first test case of the first sample one move suffices: [4,0]→[3,1].In the second test case the two passengers always have equal amounts, so no move can ever be made.In the third test case the first passenger gives one packet to each of the others: three moves.In the fourth test case the goal cannot be reached.In the first test case of the second sample, [5,5,0]→[4,5,1]→[4,4,2]→[4,3,3] reaches the multiset {3,3,4} in three moves.
