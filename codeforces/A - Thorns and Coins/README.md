# [A. Thorns and Coins](https://codeforces.com/contest/1932/problem/A)

---
During your journey through computer universes, you stumbled upon a very interesting world. It is a path with nn consecutive cells, each of which can either be empty, contain thorns, or a coin. In one move, you can move one or two cells along the path, provided that the destination cell does not contain thorns (and belongs to the path). If you move to the cell with a coin, you pick it up.  Here, green arrows correspond to legal moves, and the red arrow corresponds to an illegal move. You want to collect as many coins as possible. Find the maximum number of coins you can collect in the discovered world if you start in the leftmost cell of the path.

### Input
InputThe first line of input contains a single integer tt (1≤t≤10001≤t≤1000) — the number of test cases. Then the descriptions of the test cases follow.The first line of each test case contains a single integer nn (1≤n≤501≤n≤50) — the length of the path.The second line of each test case contains a string of nn characters, the description of the path. The character '.' denotes an empty cell, '@' denotes a cell with a coin, and '*' denotes a cell with thorns. It is guaranteed that the first cell is empty.

### Output
OutputFor each test case, output a single integer, the maximum number of coins you can collect.
NoteThe picture for the first example is in the problem statement.Here is the picture for the second example:  And here is the picture for the third example:
