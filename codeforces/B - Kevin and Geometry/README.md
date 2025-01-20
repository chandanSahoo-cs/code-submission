# [B. Kevin and Geometry](https://codeforces.com/contest/2061/problem/B)

---
Kevin has n sticks with length a1,a2,…,an.Kevin wants to select 4 sticks from these to form an isosceles trapezoid∗ with a positive area. Note that rectangles and squares are also considered isosceles trapezoids. Help Kevin find a solution. If no solution exists, output −1.∗An isosceles trapezoid is a convex quadrilateral with a line of symmetry bisecting one pair of opposite sides. In any isosceles trapezoid, two opposite sides (the bases) are parallel, and the two other sides (the legs) are of equal length.

### Input
InputEach test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows. The first line of each test case contains a single integer n (4≤n≤2⋅105).The second line contains n integers a1,a2,…,an (1≤ai≤108).It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

### Output
OutputFor each test case, output 4 integers — the lengths of sticks. If no solution exists, output −1.If there are multiple solutions, print any of them.
NoteIn the first test case, you can form an isosceles trapezoid with bases of length 5 and 10, and two legs of length 5.In the second test case, you can form an isosceles trapezoid with two bases of length 5 and two legs of length 10. A rectangle is considered an isosceles trapezoid here.In the third test case, there are no sticks with the same length. It's impossible to form an isosceles trapezoid.In the fourth test case, it's impossible to form an isosceles trapezoid with a positive area.
