# [B. Tiling Challenge](https://codeforces.com/contest/1150/problem/B)

---
One day Alice was cleaning up her basement when she noticed something very curious: an infinite set of wooden pieces! Each piece was made of five square tiles, with four tiles adjacent to the fifth center tile:    By the pieces lay a large square wooden board. The board is divided into n2n2 cells arranged into nn rows and nn columns. Some of the cells are already occupied by single tiles stuck to it. The remaining cells are free.Alice started wondering whether she could fill the board completely using the pieces she had found. Of course, each piece has to cover exactly five distinct cells of the board, no two pieces can overlap and every piece should fit in the board entirely, without some parts laying outside the board borders. The board however was too large for Alice to do the tiling by hand. Can you help determine if it's possible to fully tile the board?

### Input
InputThe first line of the input contains a single integer nn (3≤n≤503≤n≤50) — the size of the board.The following nn lines describe the board. The ii-th line (1≤i≤n1≤i≤n) contains a single string of length nn. Its jj-th character (1≤j≤n1≤j≤n) is equal to "." if the cell in the ii-th row and the jj-th column is free; it is equal to "#" if it's occupied.You can assume that the board contains at least one free cell.

### Output
OutputOutput YES if the board can be tiled by Alice's pieces, or NO otherwise. You can print each letter in any case (upper or lower).
NoteThe following sketches show the example boards and their tilings if such tilings exist:
