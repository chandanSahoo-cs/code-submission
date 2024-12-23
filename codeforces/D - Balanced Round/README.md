# [D. Balanced Round](https://codeforces.com/contest/1850/problem/D)

---
You are the author of a Codeforces round and have prepared n problems you are going to set, problem i having difficulty ai. You will do the following process:   remove some (possibly zero) problems from the list;  rearrange the remaining problems in any order you wish. A round is considered balanced if and only if the absolute difference between the difficulty of any two consecutive problems is at most k (less or equal than k).What is the minimum number of problems you have to remove so that an arrangement of problems is balanced?

### Input
InputThe first line contains a single integer t (1≤t≤1000) — the number of test cases.The first line of each test case contains two positive integers n (1≤n≤2⋅105) and k (1≤k≤109) — the number of problems, and the maximum allowed absolute difference between consecutive problems.The second line of each test case contains n space-separated integers ai (1≤ai≤109) — the difficulty of each problem.Note that the sum of n over all test cases doesn't exceed 2⋅105.

### Output
OutputFor each test case, output a single integer — the minimum number of problems you have to remove so that an arrangement of problems is balanced.
NoteFor the first test case, we can remove the first 2 problems and construct a set using problems with the difficulties [4,5,6], with difficulties between adjacent problems equal to |5−4|=1≤1 and |6−5|=1≤1.For the second test case, we can take the single problem and compose a round using the problem with difficulty 10.
