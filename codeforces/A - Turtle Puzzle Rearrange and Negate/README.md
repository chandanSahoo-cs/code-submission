# [A. Turtle Puzzle: Rearrange and Negate](https://codeforces.com/contest/1933/problem/A)

---
You are given an array a of n integers. You must perform the following two operations on the array (the first, then the second):  Arbitrarily rearrange the elements of the array or leave the order of its elements unchanged.  Choose at most one contiguous segment of elements and replace the signs of all elements in this segment with their opposites. Formally, you can choose a pair of indices l,r such that 1≤l≤r≤n and assign ai=−ai for all l≤i≤r (negate elements). Note that you may choose not to select a pair of indices and leave all the signs of the elements unchanged. What is the maximum sum of the array elements after performing these two operations (the first, then the second)?

### Input
InputThe first line of the input contains a single integer t (1≤t≤1000) — the number of test cases. The descriptions of the test cases follow.The first line of each test case contains a single integer n (1≤n≤50) — the number of elements in array a. The second line of each test case contains n integers a1,a2,…,an (−100≤ai≤100) — elements of the array.

### Output
OutputFor each test case, output the maximum sum of the array elements after sequentially performing the two given operations.
NoteIn the first test case, you can first rearrange the array to get [3,−2,−3] (operation 1), then choose l=2,r=3 and get the sum 3+−((−2)+(−3))=8 (operation 2).In the second test case, you can do nothing in both operations and get the sum 0.In the third test case, you can do nothing in both operations and get the sum 0+1=1.In the fourth test case, you can first leave the order unchanged (operation 1), then choose l=1,r=1 and get the sum −(−99)=99 (operation 2).In the fifth test case, you can first leave the order unchanged (operation 1), then choose l=2,r=3 and get the sum 10+−((−2)+(−3))+7=22 (operation 2).In the sixth test case, you can first leave the order unchanged (operation 1), then choose l=1,r=5 and get the sum −((−1)+(−2)+(−3)+(−4)+(−5))=15 (operation 2).
