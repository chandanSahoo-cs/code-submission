# [A. Guess the Maximum](https://codeforces.com/contest/1979/problem/A)

---
Alice and Bob came up with a rather strange game. They have an array of integers a1,a2,…,an. Alice chooses a certain integer k and tells it to Bob, then the following happens:  Bob chooses two integers i and j (1≤i<j≤n), and then finds the maximum among the integers ai,ai+1,…,aj;  If the obtained maximum is strictly greater than k, Alice wins, otherwise Bob wins. Help Alice find the maximum k at which she is guaranteed to win.

### Input
InputEach test consists of multiple test cases. The first line contains a single integer t (1≤t≤104) — the number of test cases. The description of the test cases follows.The first line of each test case contains a single integer n (2≤n≤5⋅104) — the number of elements in the array.The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109) — the elements of the array.It is guaranteed that the sum of n over all test cases does not exceed 5⋅104.

### Output
OutputFor each test case, output one integer — the maximum integer k at which Alice is guaranteed to win.
NoteIn the first test case, all possible subsegments that Bob can choose look as follows: [2,4],[2,4,1],[2,4,1,7],[4,1],[4,1,7],[1,7]. The maximums on the subsegments are respectively equal to 4,4,7,4,7,7. It can be shown that 3 is the largest integer such that any of the maximums will be strictly greater than it.In the third test case, the only segment that Bob can choose is [1,1]. So the answer is 0.
