# [D. Permutation Game](https://codeforces.com/contest/1968/problem/D)

---
Bodya and Sasha found a permutation p1,…,pn and an array a1,…,an. They decided to play a well-known "Permutation game".A permutation of length n is an array consisting of n distinct integers from 1 to n in arbitrary order. For example, [2,3,1,5,4] is a permutation, but [1,2,2] is not a permutation (2 appears twice in the array), and [1,3,4] is also not a permutation (n=3 but there is 4 in the array).Both of them chose a starting position in the permutation.The game lasts k turns. The players make moves simultaneously. On each turn, two things happen to each player:   If the current position of the player is x, his score increases by ax.  Then the player either stays at his current position x or moves from x to px.  The winner of the game is the player with the higher score after exactly k turns.Knowing Bodya's starting position PB and Sasha's starting position PS, determine who wins the game if both players are trying to win.

### Input
InputThe first line contains a single integer t (1≤t≤104) — the number of testcases.The first line of each testcase contains integers n, k, PB, PS (1≤PB,PS≤n≤2⋅105, 1≤k≤109) — length of the permutation, duration of the game, starting positions respectively.The next line contains n integers p1,…,pn (1≤pi≤n) — elements of the permutation p.The next line contains n integers a1,…,an (1≤ai≤109) — elements of array a.It is guaranteed that the sum of values of n over all test cases does not exceed 2⋅105.

### Output
OutputFor each testcase output:   "Bodya" if Bodya wins the game.  "Sasha" if Sasha wins the game.  "Draw" if the players have the same score.
NoteBelow you can find the explanation for the first testcase, where the game consists of k=2 turns. TurnBodya's positionBodya's scoreBodya's moveSasha's positionSasha's scoreSasha's movefirst30+a3=0+5=5stays on the same position20+a2=0+2=2moves to p2=1second35+a3=5+5=10stays on the same position12+a1=2+7=9stays on the same positionfinal results31019 As we may see, Bodya's score is greater, so he wins the game. It can be shown that Bodya always can win this game.
