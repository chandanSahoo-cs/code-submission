# [B. Vlad and Shapes](https://codeforces.com/contest/1926/problem/B)

---
Vladislav has a binary square grid of n×nn×n cells. A triangle or a square is drawn on the grid with symbols 11. As he is too busy being cool, he asks you to tell him which shape is drawn on the grid. A triangle is a shape consisting of kk (k>1k>1) consecutive rows, where the ii-th row has 2⋅i−12⋅i−1 consecutive characters 11, and the central 1s are located in one column. An upside down triangle is also considered a valid triangle (but not rotated by 90 degrees).  Two left pictures contain examples of triangles: k=4k=4, k=3k=3. The two right pictures don't contain triangles.  A square is a shape consisting of kk (k>1k>1) consecutive rows, where the ii-th row has kk consecutive characters 11, which are positioned at an equal distance from the left edge of the grid.  Examples of two squares: k=2k=2, k=4k=4. For the given grid, determine the type of shape that is drawn on it.

### Input
InputThe first line contains a single integer tt (1≤t≤1001≤t≤100) — the number of test cases.The first line of each test case contains a single integer nn (2≤n≤102≤n≤10) — the size of the grid.The next nn lines each contain nn characters 00 or 11.The grid contains exactly one triangle or exactly one square that contains all the 11s in the grid. It is guaranteed that the size of the triangle or square is greater than 11 (i.e., the shape cannot consist of exactly one 1).

### Output
OutputFor each test case, output "SQUARE" if all the 11s in the grid form a square, and "TRIANGLE" otherwise (without quotes).
