# [A. Rank Subsequence](https://codeforces.com/contest/2249/problem/A)

---
You are given n elements arranged in a line, numbered 1,2,…,n from left to right.You may delete any number of elements (possibly none). The remaining elements form a subsequence and keep their relative order. Let the length of this subsequence be m. If the element with original index i becomes the j-th element of the subsequence (1≤j≤m), define  its left rank as j, and  its right rank as m−j+1. For each element, you are given two integer segments [li,ri] and [ui,vi]. The i-th element is valid in a subsequence of length m if and only if, when it occupies position j in that subsequence, both of the following hold:  Its left rank is not in the range [li,ri] (i.e., j∉[li,ri]);  Its right rank is not in the range [ui,vi] (i.e., m−j+1∉[ui,vi]). A subsequence is valid if every element remaining in it is valid.Find the maximum possible length of a valid subsequence. The answer may be 0.

### Input
InputEach test contains multiple test cases. The first line contains the number of test cases t (1≤t≤5000). The description of the test cases follows.The first line of each test case contains a single integer n (1≤n≤5000) — the number of elements.Then n lines follow, the i-th line containing the four integers li, ri, ui, and vi (1≤i≤n, 1≤li≤ri≤n, 1≤ui≤vi≤n).It is guaranteed that the sum of n over all test cases does not exceed 5000.

### Output
OutputFor each test case, print one integer — the maximum possible length of a valid subsequence.
NoteIn the first test case, the only element cannot form a valid subsequence of length 1, so the answer is 0.In the second test case, all 4 elements can be kept. Their pairs of left and right ranks are (1,4), (2,3), (3,2), and (4,1), respectively, and all of them are valid.In the third test case, one optimal choice is to keep the elements with original indices 2, 3, and 5.In the fourth test case, keeping both elements yields a valid subsequence of length 2. Note that no valid subsequence of length 1 exists.In the fifth test case, one optimal choice is to keep the elements with original indices 3, 4, and 5.
