# [B. Three Threadlets](https://codeforces.com/contest/1881/problem/B)

---
Once upon a time, bartender Decim found three threadlets and a pair of scissors.In one operation, Decim chooses any threadlet and cuts it into two threadlets, whose lengths are positive integers and their sum is equal to the length of the threadlet being cut.For example, he can cut a threadlet of length 5 into threadlets of lengths 2 and 3, but he cannot cut it into threadlets of lengths 2.5 and 2.5, or lengths 0 and 5, or lengths 3 and 4.Decim can perform at most three operations. He is allowed to cut the threadlets obtained from previous cuts. Will he be able to make all the threadlets of equal length?

### Input
InputThe first line contains an integer t (1≤t≤104) — the number of test cases. Then follows the description of each test case.In a single line of each test case, there are three integers a, b, c (1≤a,b,c≤109) — the lengths of the threadlets.

### Output
OutputFor each test case, output "YES" if it is possible to make all the threadlets of equal length by performing at most three operations, otherwise output "NO".You can output "YES" and "NO" in any case (for example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as a positive answer).
NoteLet's consider some testcases of the first test.In the first testcase, you can apply following operations:1,3,2→1,2,1,2→1,1,1,1,2→1,1,1,1,1,1.In the second testcase, you can do nothing, the threadlets are already of equal length.In the third testcase, it isn't possible to make threadlets of equal length.
