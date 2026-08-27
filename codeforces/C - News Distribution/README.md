# [C. News Distribution](https://codeforces.com/contest/1167/problem/C)

---
In some social network, there are n users communicating with each other in m groups of friends. Let's analyze the process of distributing some news between users.Initially, some user x receives the news from some source. Then he or she sends the news to his or her friends (two users are friends if there is at least one group such that both of them belong to this group). Friends continue sending the news to their friends, and so on. The process ends when there is no pair of friends such that one of them knows the news, and another one doesn't know.For each user x you have to determine what is the number of users that will know the news if initially only user x starts distributing it.

### Input
InputThe first line contains two integers n and m (1≤n,m≤5⋅105) — the number of users and the number of groups of friends, respectively.Then m lines follow, each describing a group of friends. The i-th line begins with integer ki (0≤ki≤n) — the number of users in the i-th group. Then ki distinct integers follow, denoting the users belonging to the i-th group.It is guaranteed that m∑i=1ki≤5⋅105.

### Output
OutputPrint n integers. The i-th integer should be equal to the number of users that will know the news if user i starts distributing it.
