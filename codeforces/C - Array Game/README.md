# [C. Array Game](https://codeforces.com/contest/1904/problem/C)

---
You are given an array a of n positive integers. In one operation, you must pick some (i,j) such that 1≤i<j≤|a| and append |ai−aj| to the end of the a (i.e. increase n by 1 and set an to |ai−aj|). Your task is to minimize and print the minimum value of a after performing k operations.

### Input
InputEach test contains multiple test cases. The first line contains an integer t (1≤t≤1000) — the number of test cases. The description of the test cases follows.The first line of each test case contains two integers n and k (2≤n≤2⋅103, 1≤k≤109) — the length of the array and the number of operations you should perform.The second line of each test case contains n integers a1,a2,…,an (1≤ai≤1018) — the elements of the array a.It is guaranteed that the sum of n2 over all test cases does not exceed 4⋅106.

### Output
OutputFor each test case, print a single integer — the smallest possible value of the minimum of array a after performing k operations.
NoteIn the first test case, after any k=2 operations, the minimum value of a will be 1.In the second test case, an optimal strategy is to first pick i=1,j=2 and append |a1−a2|=3 to the end of a, creating a=[7,4,15,12,3]. Then, pick i=3,j=4 and append |a3−a4|=3 to the end of a, creating a=[7,4,15,12,3,3]. In the final operation, pick i=5,j=6 and append |a5−a6|=0 to the end of a. Then the minimum value of a will be 0.In the third test case, an optimal strategy is to first pick i=2,j=3 to append |a2−a3|=3 to the end of a. Any second operation will still not make the minimum value of a be less than 3.
