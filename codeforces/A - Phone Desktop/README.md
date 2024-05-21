# [A. Phone Desktop](https://codeforces.com/contest/1974/problem/A)

---
Little Rosie has a phone with a desktop (or launcher, as it is also called). The desktop can consist of several screens. Each screen is represented as a grid of size 5×35×3, i.e., five rows and three columns.There are xx applications with an icon size of 1×11×1 cells; such an icon occupies only one cell of the screen. There are also yy applications with an icon size of 2×22×2 cells; such an icon occupies a square of 44 cells on the screen. Each cell of each screen can be occupied by no more than one icon.Rosie wants to place the application icons on the minimum number of screens. Help her find the minimum number of screens needed.

### Input
InputThe first line of the input contains tt (1≤t≤1041≤t≤104) — the number of test cases. The first and only line of each test case contains two integers xx and yy (0≤x,y≤990≤x,y≤99) — the number of applications with a 1×11×1 icon and the number of applications with a 2×22×2 icon, respectively.

### Output
OutputFor each test case, output the minimal number of required screens on a separate line.
NoteThe solution for the first test case can look as follows:  Blue squares represent empty spaces for icons, green squares represent 1×11×1 icons, red squares represent 2×22×2 icons The solution for the third test case can look as follows:
