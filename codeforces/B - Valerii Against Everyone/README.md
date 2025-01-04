# [B. Valerii Against Everyone](https://codeforces.com/contest/1438/problem/B)

---
You're given an array bb of length nn. Let's define another array aa, also of length nn, for which ai=2biai=2bi (1≤i≤n1≤i≤n). Valerii says that every two non-intersecting subarrays of aa have different sums of elements. You want to determine if he is wrong. More formally, you need to determine if there exist four integers l1,r1,l2,r2l1,r1,l2,r2 that satisfy the following conditions:   1≤l1≤r1<l2≤r2≤n1≤l1≤r1<l2≤r2≤n;  al1+al1+1+…+ar1−1+ar1=al2+al2+1+…+ar2−1+ar2al1+al1+1+…+ar1−1+ar1=al2+al2+1+…+ar2−1+ar2. If such four integers exist, you will prove Valerii wrong. Do they exist?An array cc is a subarray of an array dd if cc can be obtained from dd by deletion of several (possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end.

### Input
InputEach test contains multiple test cases. The first line contains the number of test cases tt (1≤t≤1001≤t≤100). Description of the test cases follows.The first line of every test case contains a single integer nn (2≤n≤10002≤n≤1000).The second line of every test case contains nn integers b1,b2,…,bnb1,b2,…,bn (0≤bi≤1090≤bi≤109).

### Output
OutputFor every test case, if there exist two non-intersecting subarrays in aa that have the same sum, output YES on a separate line. Otherwise, output NO on a separate line. Also, note that each letter can be in any case.
NoteIn the first case, a=[16,8,1,2,4,1]a=[16,8,1,2,4,1]. Choosing l1=1l1=1, r1=1r1=1, l2=2l2=2 and r2=6r2=6 works because 16=(8+1+2+4+1)16=(8+1+2+4+1).In the second case, you can verify that there is no way to select to such subarrays.
