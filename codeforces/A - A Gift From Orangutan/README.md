# [A. A Gift From Orangutan](https://codeforces.com/contest/2030/problem/A)

---
While exploring the jungle, you have bumped into a rare orangutan with a bow tie! You shake hands with the orangutan and offer him some food and water. In return...The orangutan has gifted you an array a of length n. Using a, you will construct two arrays b and c, both containing n elements, in the following manner:  bi=min(a1,a2,…,ai) for each 1≤i≤n.  ci=max(a1,a2,…,ai) for each 1≤i≤n. Define the score of a as ∑ni=1ci−bi (i.e. the sum of ci−bi over all 1≤i≤n). Before you calculate the score, you can shuffle the elements of a however you want.Find the maximum score that you can get if you shuffle the elements of a optimally.

### Input
InputThe first line contains t (1≤t≤100) — the number of test cases.The first line of each test case contains an integer n (1≤n≤1000) — the number of elements in a.The following line contains n integers a1,a2,…,an (1≤ai≤1000) — the elements of the array a.It is guaranteed that the sum of n over all test cases does not exceed 1000.

### Output
OutputFor each test case, output the maximum score that you can get.
NoteIn the first test case, there is no other way to rearrange a. So, b=[69] and c=[69]. The only possible score is 69−69=0.In the second test case, you can rearrange a as [7,5,6]. Here, b=[7,5,5] and c=[7,7,7]. The score in this case is (7−7)+(7−5)+(7−5)=4. It can be shown this is the maximum possible score.
