# [B. Turtle Math: Fast Three Task](https://codeforces.com/contest/1933/problem/B)

---
You are given an array a1,a2,…,an.In one move, you can perform either of the following two operations:  Choose an element from the array and remove it from the array. As a result, the length of the array decreases by 1; Choose an element from the array and increase its value by 1. You can perform any number of moves. If the current array becomes empty, then no more moves can be made.Your task is to find the minimum number of moves required to make the sum of the elements of the array a divisible by 3. It is possible that you may need 0 moves.Note that the sum of the elements of an empty array (an array of length 0) is equal to 0.

### Input
InputThe first line of the input contains a single integer t (1≤t≤104) — the number of test cases.The first line of each test case contains a single integer n (1≤n≤105).The second line of each test case contains n integers a1,a2,…,an (1≤ai≤104).The sum of n over all test cases does not exceed 2⋅105.

### Output
OutputFor each test case, output a single integer: the minimum number of moves.
NoteIn the first test case, initially the array a=[2,2,5,4]. One of the optimal ways to make moves is:   remove the current 4th element and get a=[2,2,5];  As a result, the sum of the elements of the array a will be divisible by 3 (indeed, a1+a2+a3=2+2+5=9).In the second test case, initially, the sum of the array is 1+3+2=6, which is divisible by 3. Therefore, no moves are required. Hence, the answer is 0.In the fourth test case, initially, the sum of the array is 1, which is not divisible by 3. By removing its only element, you will get an empty array, so its sum is 0. Hence, the answer is 1.
