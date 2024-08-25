# [C. Turtle and Good Pairs](https://codeforces.com/contest/2003/problem/C)

---
Turtle gives you a string ss, consisting of lowercase Latin letters.Turtle considers a pair of integers (i,j)(i,j) (1≤i<j≤n1≤i<j≤n) to be a pleasant pair if and only if there exists an integer kk such that i≤k<ji≤k<j and both of the following two conditions hold:  sk≠sk+1sk≠sk+1;  sk≠sisk≠si or sk+1≠sjsk+1≠sj. Besides, Turtle considers a pair of integers (i,j)(i,j) (1≤i<j≤n1≤i<j≤n) to be a good pair if and only if si=sjsi=sj or (i,j)(i,j) is a pleasant pair.Turtle wants to reorder the string ss so that the number of good pairs is maximized. Please help him!

### Input
InputEach test contains multiple test cases. The first line contains the number of test cases tt (1≤t≤1041≤t≤104). The description of the test cases follows.The first line of each test case contains a single integer nn (2≤n≤2⋅1052≤n≤2⋅105) — the length of the string.The second line of each test case contains a string ss of length nn, consisting of lowercase Latin letters.It is guaranteed that the sum of nn over all test cases does not exceed 2⋅1052⋅105.

### Output
OutputFor each test case, output the string ss after reordering so that the number of good pairs is maximized. If there are multiple answers, print any of them.
NoteIn the first test case, (1,3)(1,3) is a good pair in the reordered string. It can be seen that we can't reorder the string so that the number of good pairs is greater than 11. bac and cab can also be the answer.In the second test case, (1,2)(1,2), (1,4)(1,4), (1,5)(1,5), (2,4)(2,4), (2,5)(2,5), (3,5)(3,5) are good pairs in the reordered string. efddd can also be the answer.
