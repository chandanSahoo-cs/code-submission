# [D. I Love 1543](https://codeforces.com/contest/2036/problem/D)

---
One morning, Polycarp woke up and realized that 15431543 is the most favorite number in his life.The first thing that Polycarp saw that day as soon as he opened his eyes was a large wall carpet of size nn by mm cells; nn and mm are even integers. Each cell contains one of the digits from 00 to 99.Polycarp became curious about how many times the number 15431543 would appear in all layers∗∗ of the carpet when traversed clockwise.∗∗The first layer of a carpet of size n×mn×m is defined as a closed strip of length 2⋅(n+m−2)2⋅(n+m−2) and thickness of 11 element, surrounding its outer part. Each subsequent layer is defined as the first layer of the carpet obtained by removing all previous layers from the original carpet.

### Input
InputThe first line of the input contains a single integer tt (1≤t≤1001≤t≤100) — the number of test cases. The following lines describe the test cases.The first line of each test case contains a pair of numbers nn and mm (2≤n,m≤1032≤n,m≤103, n,mn,m — even integers).This is followed by nn lines of length mm, consisting of digits from 00 to 99 — the description of the carpet.It is guaranteed that the sum of n⋅mn⋅m across all test cases does not exceed 106106.

### Output
OutputFor each test case, output a single number — the total number of times 15431543 appears in all layers of the carpet in the order of traversal clockwise.
Note  Occurrences of 15431543 in the seventh example. Different layers are colored in different colors.
