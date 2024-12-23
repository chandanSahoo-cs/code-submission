# [A. Make It Zero](https://codeforces.com/contest/1869/problem/A)

---
During Zhongkao examination, Reycloer met an interesting problem, but he cannot come up with a solution immediately. Time is running out! Please help him.Initially, you are given an array a consisting of n≥2 integers, and you want to change all elements in it to 0.In one operation, you select two indices l and r (1≤l≤r≤n) and do the following:  Let s=al⊕al+1⊕…⊕ar, where ⊕ denotes the bitwise XOR operation;  Then, for all l≤i≤r, replace ai with s. You can use the operation above in any order at most 8 times in total.Find a sequence of operations, such that after performing the operations in order, all elements in a are equal to 0. It can be proven that the solution always exists.

### Input
InputThe first line of input contains a single integer t (1≤t≤500) — the number of test cases. The description of test cases follows.The first line of each test case contains a single integer n (2≤n≤100) — the length of the array a.The second line of each test case contains n integers a1,a2,…,an (0≤ai≤100) — the elements of the array a.

### Output
OutputFor each test case, in the first line output a single integer k (0≤k≤8) — the number of operations you use.Then print k lines, in the i-th line output two integers li and ri (1≤li≤ri≤n) representing that you select li and ri in the i-th operation. Note that you do not have to minimize k. If there are multiple solutions, you may output any of them.
NoteIn the first test case, since 1⊕2⊕3⊕0=0, after performing the operation on segment [1,4], all the elements in the array are equal to 0.In the second test case, after the first operation, the array becomes equal to [3,1,4,15,15,15,15,6], after the second operation, the array becomes equal to [0,0,0,0,0,0,0,0].In the third test case: Operationa beforea after1[1,5_,4,1,4,7]→[4,4,4,1,4,7]2[4,4,4,1_,4,7]→[4,4,5,5,4,7]3[4,4,5,5,4,7_]→[4,4,5,5,3,3]4[4,4,5_,5,3,3]→[5,5,5,5,3,3]5[5,5,5,5,3,3_]→[5,5,5,5,5,5]6[5,5,5,5,5,5_]→[0,0,0,0,0,0] In the fourth test case, the initial array contains only 0, so we do not need to perform any operations with it.
