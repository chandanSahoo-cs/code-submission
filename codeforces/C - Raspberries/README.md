# [C. Raspberries](https://codeforces.com/contest/1883/problem/C)

---
You are given an array of integers a1,a2,…,an and a number k (2≤k≤5). In one operation, you can do the following: Choose an index 1≤i≤n, Set ai=ai+1.Find the minimum number of operations needed to make the product of all the numbers in the array a1⋅a2⋅…⋅an divisible by k.

### Input
InputEach test consists of multiple test cases. The first line contains a single integer t (1≤t≤104) — the number of test cases. Then follows the description of the test cases.The first line of each test case contains two integers n and k (2≤n≤105, 2≤k≤5) — the size of the array a and the number k.The second line of each test case contains n integers a1,a2,…,an (1≤ai≤10).It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

### Output
OutputFor each test case, output the minimum number of operations needed to make the product of all the numbers in the array divisible by k.
NoteIn the first test case, we need to choose the index i=2 twice. After that, the array will be a=[7,5]. The product of all the numbers in the array is 35.In the fourth test case, the product of the numbers in the array is 120, which is already divisible by 5, so no operations are needed.In the eighth test case, we can perform two operations by choosing i=2 and i=3 in any order. After that, the array will be a=[1,6,10]. The product of the numbers in the array is 60.
