# [A. Rectangle Cutting](https://codeforces.com/contest/1928/problem/A)

---
Bob has a rectangle of size a×ba×b. He tries to cut this rectangle into two rectangles with integer sides by making a cut parallel to one of the sides of the original rectangle. Then Bob tries to form some other rectangle from the two resulting rectangles, and he can rotate and move these two rectangles as he wishes.Note that if two rectangles differ only by a 90∘90∘ rotation, they are considered the same. For example, the rectangles 6×46×4 and 4×64×6 are considered the same.Thus, from the 2×62×6 rectangle, another rectangle can be formed, because it can be cut into two 2×32×3 rectangles, and then these two rectangles can be used to form the 4×34×3 rectangle, which is different from the 2×62×6 rectangle.  However, from the 2×12×1 rectangle, another rectangle cannot be formed, because it can only be cut into two rectangles of 1×11×1, and from these, only the 1×21×2 and 2×12×1 rectangles can be formed, which are considered the same.  Help Bob determine if he can obtain some other rectangle, or if he is just wasting his time.

### Input
InputEach test consists of multiple test cases. The first line contains a single integer tt (1≤t≤1041≤t≤104) — the number of test cases. This is followed by the description of the test cases.The single line of each test case contains two integers aa and bb (1≤a,b≤1091≤a,b≤109) — the size of Bob's rectangle.

### Output
OutputFor each test case, output "Yes" if Bob can obtain another rectangle from the a×ba×b rectangle. Otherwise, output "No".You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive answers.
NoteIn the first test case, the 1×11×1 rectangle cannot be cut into two rectangles, so another rectangle cannot be obtained from it.In the fourth test case, the 3×23×2 rectangle can be cut into two 3×13×1 rectangles, and from these, the 1×61×6 rectangle can be formed.In the fifth test case, the 2×22×2 rectangle can be cut into two 1×21×2 rectangles, and from these, the 1×41×4 rectangle can be formed.
