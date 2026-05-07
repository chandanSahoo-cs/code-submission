# [D. Penchick and Desert Rabbit](https://codeforces.com/contest/2031/problem/D)

---
Dedicated to pushing himself to his limits, Penchick challenged himself to survive the midday sun in the Arabian Desert!While trekking along a linear oasis, Penchick spots a desert rabbit preparing to jump along a line of palm trees. There are n trees, each with a height denoted by ai.The rabbit can jump from the i-th tree to the j-th tree if exactly one of the following conditions is true:  j<i and aj>ai: the rabbit can jump backward to a taller tree.  j>i and aj<ai: the rabbit can jump forward to a shorter tree. For each i from 1 to n, determine the maximum height among all trees that the rabbit can reach if it starts from the i-th tree.

### Input
InputThe first line contains the number of test cases t (1≤t≤5⋅105). The description of the test cases follows.The first line of each test case contains a single integer n (1≤n≤5⋅105) — the number of trees.The second line of each test case contains n integers a1,a2,…,an (1≤ai≤n) — the height of the trees.It is guaranteed that the sum of n over all test cases does not exceed 5⋅105.

### Output
OutputFor each test case, output n integers. The i-th integer should contain the maximum height among all trees that the rabbit can reach if it starts from the i-th tree.
NoteIn the first test case, the initial heights of trees are a=[2,3,1,4].   If the rabbit starts from the first tree, it can jump to the third tree as 3>1 and 1<2. Then, the rabbit can jump to the second tree as 2<3 and 3>1. It can be proved that the rabbit cannot reach the fourth tree; hence, the maximum height of the tree that the rabbit can reach is a2=3.  If the rabbit starts from the fourth tree, it does not need to jump anywhere as it is already at the highest tree. In the second test case, the rabbit can jump to the first tree regardless of which tree it starts from.In the fifth test case, if the rabbit starts from the fifth tree, it can jump to the fourth tree. Then the rabbit can jump to the seventh tree and finally reach the sixth tree. Therefore, the maximum height of the tree that the rabbit can reach is 8.
