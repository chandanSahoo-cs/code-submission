# [A. Threshold Movement](https://codeforces.com/contest/2250/problem/A)

---
There are n+2 positions numbered from 0 to n+1. Initially, position i contains an element of weight wi for every 1≤i≤n, while positions 0 and n+1 are empty.You choose an integer k. Then every element moves exactly once, simultaneously:  If wi<k, the element at position i moves to position i−1;  If wi>k, the element at position i moves to position i+1;  If wi=k, the entire movement process fails immediately. An integer k is perfect if the movement does not fail and, upon completion, every position from 1 to n contains exactly one element.Determine whether a perfect integer k exists.

### Input
InputEach test contains multiple test cases. The first line contains the number of test cases t (1≤t≤500). The description of the test cases follows.The first line of each test case contains one integer n (1≤n≤100).The second line of each test case contains n integers w1,w2,…,wn (1≤wi≤109).

### Output
OutputFor each test case, print "YES" if a perfect integer k exists, and "NO" otherwise.You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.
NoteIn the first test case, the only element either leaves position 1 or has weight equal to k, so no suitable integer exists.In the second test case, choose k=2. The element of weight 3 moves right and the element of weight 1 moves left, leaving one element in each position.In the third test case, keeping both positions occupied would require 1<k<2, which is impossible for an integer k.In the fourth test case, k=5 is suitable: the elements at positions 1 and 3 move right, while those at positions 2 and 4 move left. Upon completion, every position from 1 to 4 contains exactly one element.In the fifth test case, the element at position 2 must move left, requiring k>8, while the element at position 3 must move right, requiring k<7. These requirements are incompatible.In the sixth test case, choose k=4. All elements at odd positions move right and all elements at even positions move left, so every position from 1 to 6 contains one element afterwards.
