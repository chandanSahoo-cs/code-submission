# [C. Stepan and Permutation](https://codeforces.com/contest/2244/problem/C)

---
Stepan found a permutation pp of length nn. Of course, he decided to sort it. To make the process more interesting, he chose two positive integers xx and yy (x+y≤n)(x+y≤n) and defined a rule for swapping elements.In one move, Stepan can choose two indices ii and jj (1≤i,j≤n)(1≤i,j≤n) and swap the elements pipi and pjpj if at least one of the following conditions holds:  |i−j|=x|i−j|=x  |i−j|=y|i−j|=y Stepan wants to know whether it is possible to sort the permutation in ascending order using any number of such operations. Help him answer this question.

### Input
InputThe first line contains a single integer tt (1≤t≤104)(1≤t≤104) — the number of test cases.The first line of each test case contains three integers nn, xx, and yy (1≤x,y≤n≤2⋅105(1≤x,y≤n≤2⋅105, x+y≤n)x+y≤n) — the length of the array and the numbers chosen by Stepan.The second line of each test case contains nn integers pipi (1≤pi≤n)(1≤pi≤n) — the array pp; it is guaranteed that pp is a permutation.It is guaranteed that the sum of nn over all test cases does not exceed 2⋅1052⋅105.

### Output
OutputFor each test case, output "YES" if it is possible to sort the permutation with the given xx and yy, and "NO" otherwise.You may output each letter in any case (lowercase or uppercase). For example, the strings "yEs", "yes", "Yes", and "YES" will be accepted.
