# [B. Make It Ugly](https://codeforces.com/contest/1954/problem/B)

---
Let's call an array a beautiful if you can make all its elements the same by using the following operation an arbitrary number of times (possibly, zero):   choose an index i (2≤i≤|a|−1) such that ai−1=ai+1, and replace ai with ai−1. You are given a beautiful array a1,a2,…,an. What is the minimum number of elements you have to remove from it in order for it to stop being beautiful? Swapping elements is prohibited. If it is impossible to do so, then output -1.

### Input
InputThe first line contains a single integer t (1≤t≤104) — the number of test cases.The first line of each test case contains a single integer n (1≤n≤3⋅105).The second line contains n integers a1,a2,…,an (1≤ai≤n).Additional constraints on the input:  in every test case, the given array a is beautiful;  the sum of n over all test cases does not exceed 3⋅105.

### Output
OutputFor each test case, output a single integer — the minimum number of elements you have to remove from the array a in order for it to stop being beautiful. If it is impossible, then output -1.
NoteIn the first testcase, it is impossible to modify the array in such a way that it stops being beautiful. An array consisting of identical numbers will remain beautiful no matter how many numbers we remove from it.In the second testcase, you can remove the number at the index 5, for example.The resulting array will be [1,2,1,2]. Let's check if it is beautiful. Two operations are available:   Choose i=2: the array becomes [1,1,1,2]. No more operations can be applied to it, and the numbers are not all the same.  Choose i=3 instead: the array becomes [1,2,2,2]. No more operations can be applied to it either, and the numbers are still not all the same. Thus, the array [1,2,1,2] is not beautiful.In the fourth testcase, you can remove the first three elements, for example. The resulting array [5,3,3,3] is not beautiful.
