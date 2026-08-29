# [A. Odd Eraser](https://codeforces.com/contest/2258/problem/A)

---
Given an array a1,a2,…,an, you can apply the following operation any number of times (possibly zero):   Choose an integer k≥1 such that 2k+1≤m and 2k+1 indices, i1,i2,…,i2k+1 (1≤i1<i2<…<i2k+1≤m), where m is the current length of the array. Then, remove the ik+1-th element from the array.  Note that after any operation, the length of the array is reduced by one, and the rest of the array is concatenated. Let b1,b2,…,bm be the remaining array after all operations. What is the maximum possible value of gcd(b1,b2,…,bm), where gcd of an array of integers denotes the greatest common divisor (GCD) of them?

### Input
InputEach test contains multiple test cases. The first line contains the number of test cases t (1≤t≤500). The description of the test cases follows.The first line of each test case contains n (1≤n≤100), denoting the size of the array. The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109).

### Output
OutputFor each test case, output a single integer — the maximum possible value.
NoteIn the first test case, the given array is [2,4,6,7,8,9,10]. Choosing indices [1,3,4,6,7] results in the removal of a4=7 and the array [2,4,6,8,9,10]. Then, choosing indices [2,5,6] results in the removal of a5=9 and the array [2,4,6,8,10]. You can't get an answer greater than 2.
