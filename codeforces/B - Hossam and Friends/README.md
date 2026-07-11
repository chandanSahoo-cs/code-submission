# [B. Hossam and Friends](https://codeforces.com/contest/1771/problem/B)

---
Hossam makes a big party, and he will invite his friends to the party.He has n friends numbered from 1 to n. They will be arranged in a queue as follows: 1,2,3,…,n.Hossam has a list of m pairs of his friends that don't know each other. Any pair not present in this list are friends.A subsegment of the queue starting from the friend a and ending at the friend b is [a,a+1,a+2,…,b]. A subsegment of the queue is called good when all pairs of that segment are friends.Hossam wants to know how many pairs (a,b) there are (1≤a≤b≤n), such that the subsegment starting from the friend a and ending at the friend b is good.

### Input
InputThe input consists of multiple test cases. The first line contains a single integer t (1≤t≤2⋅104), the number of test cases. Description of the test cases follows.The first line of each test case contains two integer numbers n and m (2≤n≤105, 0≤m≤105) representing the number of friends and the number of pairs, respectively.The i-th of the next m lines contains two integers xi and yi (1≤xi,yi≤n, xi≠yi) representing a pair of Hossam's friends that don't know each other.Note that pairs can be repeated.It is guaranteed that the sum of n over all test cases does not exceed 105, and the sum of m over all test cases does not exceed 105.

### Output
OutputFor each test case print an integer — the number of good subsegments.
NoteIn the first example, the answer is 4.The good subsegments are:[1][2][3][1, 2]In the second example, the answer is 5.The good subsegments are:[1][2][3][4][3, 4]
