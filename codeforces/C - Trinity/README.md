# [C. Trinity](https://codeforces.com/contest/2032/problem/C)

---
You are given an array a of n elements a1,a2,…,an.You can perform the following operation any number (possibly 0) of times:  Choose two integers i and j, where 1≤i,j≤n, and assign ai:=aj. Find the minimum number of operations required to make the array a satisfy the condition:  For every pairwise distinct triplet of indices (x,y,z) (1≤x,y,z≤n, x≠y, y≠z, x≠z), there exists a non-degenerate triangle with side lengths ax, ay and az, i.e. ax+ay>az, ay+az>ax and az+ax>ay.

### Input
InputEach test consists of multiple test cases. The first line contains a single integer t (1≤t≤104) — the number of test cases. The description of the test cases follows.The first line of each test case contains a single integer n (3≤n≤2⋅105) — the number of elements in the array a.The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109) — the elements of the array a.It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

### Output
OutputFor each test case, output a single integer — the minimum number of operations required.
NoteIn the first test case, one of the possible series of operations would be:  Assign a1:=a4=4. The array will become [4,2,3,4,5,6,7].  Assign a2:=a5=5. The array will become [4,5,3,4,5,6,7].  Assign a7:=a1=4. The array will become [4,5,3,4,5,6,4]. It can be proven that any triplet of elements with pairwise distinct indices in the final array forms a non-degenerate triangle, and there is no possible answer using less than 3 operations.In the second test case, we can assign a1:=a2=3 to make the array a=[3,3,2].In the third test case, since 3, 4 and 5 are valid side lengths of a triangle, we don't need to perform any operation to the array.
