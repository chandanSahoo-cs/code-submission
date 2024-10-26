# [E. Sakurako, Kosuke, and the Permutation](https://codeforces.com/contest/2033/problem/E)

---
Sakurako's exams are over, and she did excellently. As a reward, she received a permutation p. Kosuke was not entirely satisfied because he failed one exam and did not receive a gift. He decided to sneak into her room (thanks to the code for her lock) and spoil the permutation so that it becomes simple.A permutation p is considered simple if for every i (1≤i≤n) one of the following conditions holds:  pi=i  ppi=i For example, the permutations [1,2,3,4], [5,2,4,3,1], and [2,1] are simple, while [2,3,1] and [5,2,1,4,3] are not.In one operation, Kosuke can choose indices i,j (1≤i,j≤n) and swap the elements pi and pj.Sakurako is about to return home. Your task is to calculate the minimum number of operations that Kosuke needs to perform to make the permutation simple.

### Input
InputThe first line contains one integer t (1≤t≤104) — the number of test cases.Each test case is described by two lines.  The first line contains one integer n (1≤n≤106) — the length of the permutation p.  The second line contains n integers pi (1≤pi≤n) — the elements of the permutation p. It is guaranteed that the sum of n across all test cases does not exceed 106.It is guaranteed that p is a permutation.

### Output
OutputFor each test case, output the minimum number of operations that Kosuke needs to perform to make the permutation simple.
NoteIn the first and second examples, the permutations are already simple.In the fourth example, it is sufficient to swap p2 and p4. Thus, the permutation will become [2,1,4,3] in 1 operation.
