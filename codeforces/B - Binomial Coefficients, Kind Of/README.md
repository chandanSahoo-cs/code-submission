# [B. Binomial Coefficients, Kind Of](https://codeforces.com/contest/2025/problem/B)

---
Recently, akshiM met a task that needed binomial coefficients to solve. He wrote a code he usually does that looked like this:    for (int n = 0; n < N; n++) { // loop over n from 0 to N-1 (inclusive)        C[n][0] = 1;        C[n][n] = 1;        for (int k = 1; k < n; k++) // loop over k from 1 to n-1 (inclusive)            C[n][k] = C[n][k - 1] + C[n - 1][k - 1];    }Unfortunately, he made an error, since the right formula is the following:            C[n][k] = C[n - 1][k] + C[n - 1][k - 1]But his team member keblidA is interested in values that were produced using the wrong formula. Please help him to calculate these coefficients for t various pairs (ni,ki). Note that they should be calculated according to the first (wrong) formula.Since values C[ni][ki] may be too large, print them modulo 109+7.

### Input
InputThe first line contains a single integer t (1≤t≤105) — the number of pairs. Next, t pairs are written in two lines.The second line contains t integers n1,n2,…,nt (2≤ni≤105).The third line contains t integers k1,k2,…,kt (1≤ki<ni).

### Output
OutputPrint t integers C[ni][ki] modulo 109+7.
