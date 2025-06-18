# [E. Romantic Glasses](https://codeforces.com/contest/1915/problem/E)

---
Iulia has n glasses arranged in a line. The i-th glass has ai units of juice in it. Iulia drinks only from odd-numbered glasses, while her date drinks only from even-numbered glasses.To impress her date, Iulia wants to find a contiguous subarray of these glasses such that both Iulia and her date will have the same amount of juice in total if only the glasses in this subarray are considered. Please help her to do that.More formally, find out if there exists two indices l, r such that 1≤l≤r≤n, and al+al+2+al+4+⋯+ar=al+1+al+3+⋯+ar−1 if l and r have the same parity and al+al+2+al+4+⋯+ar−1=al+1+al+3+⋯+ar otherwise.

### Input
InputThe first line contains a single integer t (1≤t≤104) — the number of test cases.The first line of each test case contains a single integer n (1≤n≤2⋅105) — the total number of glasses.The second line of each test case contains n integers a1,…,an (1≤ai≤109) — the amount of juice in each glass.The sum of n over all test cases does not exceed 2⋅105.

### Output
OutputFor each test case, output "YES" if there exists a subarray satisfying the condition, and "NO" otherwise.You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive answer).
NoteIn the first test case, Iulia can pick l=1 and r=3. Then she drinks a1+a3=1+2=3 units and her date drinks a2=3 units of juice.In the second test case, Iulia can pick l=2 and r=5. Then she drinks a3+a5=1+1=2 units and her date drinks a2+a4=1+1=2 units of juice.In the third test case no such contiguous subarray works.In the fourth test case, Iulia can pick l=2 and r=8. Then she drinks a3+a5+a7=11+1+1=13 units and her date drinks a2+a4+a6+a8=2+4+5+2=13 units of juice.
