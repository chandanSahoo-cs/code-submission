# [A. The Night Walk](https://codeforces.com/gym/720455/problem/A)

---
Kanpur taught Team MST a lot, mostly about what not to do. Now it is Amritapuri, their second regional: two days away by train, and Coach Tanima could not get enough leave, so the three of them travel alone. Tonight they board the train at Varanasi: their first time this far south and, for Enigma, his first AC coach.Nobody can sleep. The coach corridor runs from the door at position 0 to the door at position L. At time 0 the coach attendant leaves the door at 0 and walks towards L at speed 1 (one unit of length per second). Whenever he reaches a door, he instantly turns around and keeps walking at the same speed. This goes on all night.The team's n bags stand in the corridor; the i-th bag is at integer position xi, where 0<xi<L, and all positions are distinct. Lying awake, Enigma counts one every time the attendant is exactly at the position of a bag.How many times does Enigma count during the moments t with 0<t≤D? Different bags are counted separately.

### Input
InputThe first line contains an integer T (1≤T≤104) — the number of test cases. The test cases follow.The first line of each test case contains three integers n, L, D (2≤L≤109, 1≤n≤min(L−1, 2⋅105), 1≤D≤109) — the number of bags, the position of the far door, and the length of the night.The second line contains n distinct integers x1,x2,…,xn (0<xi<L) — the positions of the bags.It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

### Output
OutputFor each test case print one integer — the number of times Enigma counts during the moments t with 0<t≤D.
NoteIn the first test case of the first sample, L=5 and D=12. The attendant is at position 1 at moments 1, 9 and 11, and at position 4 at moments 4 and 6. Enigma counts 5 times.In the second test case the attendant reaches the only bag at moment 1=D.In the third test case Enigma counts 3⋅108 times.
