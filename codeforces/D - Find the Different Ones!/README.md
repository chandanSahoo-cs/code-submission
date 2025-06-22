# [D. Find the Different Ones!](https://codeforces.com/contest/1927/problem/D)

---
You are given an array a of n integers, and q queries.Each query is represented by two integers l and r (1≤l≤r≤n). Your task is to find, for each query, two indices i and j (or determine that they do not exist) such that:  l≤i≤r;  l≤j≤r;  ai≠aj. In other words, for each query, you need to find a pair of different elements among al,al+1,…,ar, or report that such a pair does not exist.

### Input
InputThe first line of the input contains a single integer t (1≤t≤104) — the number of test cases. The descriptions of the test cases follow.The first line of each test case contains a single integer n (2≤n≤2⋅105) — the length of the array a.The second line of each test case contains n integers a1,a2,…,an (1≤ai≤106) — the elements of the array a.The third line of each test case contains a single integer q (1≤q≤2⋅105) — the number of queries.The next q lines contain two integers each, l and r (1≤l<r≤n) — the boundaries of the query.It is guaranteed that the sum of the values of n across all test cases does not exceed 2⋅105. Similarly, it is guaranteed that the sum of the values of q across all test cases does not exceed 2⋅105.

### Output
OutputFor each query, output two integers separated by space: i and j (l≤i,j≤r), for which ai≠aj. If such a pair does not exist, output i=−1 and j=−1.You may separate the outputs for the test cases with empty lines. This is not a mandatory requirement.
