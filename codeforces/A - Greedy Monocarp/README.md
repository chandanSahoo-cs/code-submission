# [A. Greedy Monocarp](https://codeforces.com/contest/2042/problem/A)

---
There are n chests; the i-th chest initially contains ai coins. For each chest, you can choose any non-negative (0 or greater) number of coins to add to that chest, with one constraint: the total number of coins in all chests must become at least k.After you've finished adding coins to the chests, greedy Monocarp comes, who wants the coins. He will take the chests one by one, and since he is greedy, he will always choose the chest with the maximum number of coins. Monocarp will stop as soon as the total number of coins in chests he takes is at least k.You want Monocarp to take as few coins as possible, so you have to add coins to the chests in such a way that, when Monocarp stops taking chests, he will have exactly k coins. Calculate the minimum number of coins you have to add.

### Input
InputThe first line contains one integer t (1≤t≤1000) — the number of test cases.Each test case consists of two lines:  the first line contains two integers n and k (1≤n≤50; 1≤k≤107);  the second line contains n integers a1,a2,…,an (1≤ai≤k).

### Output
OutputFor each test case, print one integer — the minimum number of coins you have to add so that, when Monocarp stops taking the chests, he has exactly k coins. It can be shown that under the constraints of the problem, it is always possible.
NoteIn the first test case of the example, you don't have to add any coins. When Monocarp arrives, he will take the chest with 4 coins, so he will have exactly 4 coins.In the second test case of the example, you can add 1 coin to the 4-th chest, so, when Monocarp arrives, he will take a chest with 4 coins, then another chest with 4 coins, and a chest with 2 coins.In the third test case of the example, you can add 3 coins to the 1-st chest and 5 coins to the 2-nd chest.In the fourth test case of the example, you can add 1 coin to the 1-st chest and 1 coin to the 3-rd chest.
