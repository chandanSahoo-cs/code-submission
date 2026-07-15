# [A. Iskander and Drawings](https://codeforces.com/contest/2244/problem/A)

---
During a geometry lesson, Iskander got very bored, so he decided to draw in Yura's notebook. To do this, he took a row and drew horizontal lines on it. Some lines are long, some are short, and some parts of the page remain empty.The page is represented by a string ss, where the character '*' denotes an empty part of the paper, and the character '#' denotes one centimeter of a drawn line. A continuous sequence of '#' characters forms a single line.Yura decided to erase all the lines and made Iskander help him: they will erase one of the lines from both ends simultaneously.  Each second, Iskander erases 11 centimeter from the right end of the line, and Yura erases 11 centimeter from the left end.  If the current length of the line is 11 or 22 centimeters, then in the next second it is erased completely, and the process ends. Yura wants to choose a line so that, together with Iskander, they erase it for as long as possible. Help him determine this maximum time. If there are no lines on the page, the answer is 00 seconds.

### Input
InputThe first line contains a single integer tt (1≤t≤25001≤t≤2500) — the number of test cases.The first line of each test case contains an integer nn (1≤n≤101≤n≤10) — the length of the string ss.The second line of each test case contains a string ss of length nn, consisting of characters '#' and '*'.

### Output
OutputFor each test case, output a single integer — the maximum time required to erase a line.
