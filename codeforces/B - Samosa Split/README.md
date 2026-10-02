# [B. Samosa Split](https://codeforces.com/gym/720455/problem/B)

---
In the morning, somewhere after Prayagraj, the samosas arrive. They are spread over nn compartments of the coach, and compartment ii has aiai pieces of samosa.The pantry boy has a strange habit. He may carry a piece from a compartment ii with 1≤i<n1≤i<n and ai≥1ai≥1 to the next compartment i+1i+1, and on the way he always cuts it into two: compartment ii loses one piece and compartment i+1i+1 gains two. Pieces are never carried backwards.Shanky has a plan: compartment jj should end up with exactly bjbj pieces, for every jj (1≤j≤n1≤j≤n). Determine whether some sequence of zero or more carries turns aa into exactly bb. If it does, print the number of carries in such a sequence. It can be shown that this number is the same for every sequence that turns aa into bb, and that it fits into a signed 6464-bit integer.

### Input
InputThe first line contains an integer TT (1≤T≤1041≤T≤104) — the number of test cases. The test cases follow.The first line of each test case contains an integer nn (1≤n≤2⋅1051≤n≤2⋅105) — the number of compartments.The second line contains n integers a1,a2,…,an (0≤ai≤109) — the current numbers of pieces.The third line contains n integers b1,b2,…,bn (0≤bi≤109) — the numbers of pieces in Shanky's plan.It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

### Output
OutputFor each test case print one integer — the number of carries in a sequence that turns a into b, or −1 if a cannot be turned into b.
NoteIn the first test case of the first sample: [1,0,0]→[0,2,0]→[0,1,2]→[0,0,4], three carries.In the second test case nothing has to be carried.In the third and fourth test cases the plan cannot be reached.In the second test case of the second sample: [1,0,0,0]→[0,2,0,0]→[0,1,2,0]→[0,1,1,2]→[0,1,0,4], four carries.
