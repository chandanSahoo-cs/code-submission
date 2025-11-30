# [B. Balanced Tunnel](https://codeforces.com/contest/1237/problem/B)

---
Consider a tunnel on a one-way road. During a particular day, nn cars numbered from 11 to nn entered and exited the tunnel exactly once. All the cars passed through the tunnel at constant speeds.A traffic enforcement camera is mounted at the tunnel entrance. Another traffic enforcement camera is mounted at the tunnel exit. Perfectly balanced.Thanks to the cameras, the order in which the cars entered and exited the tunnel is known. No two cars entered or exited at the same time.Traffic regulations prohibit overtaking inside the tunnel. If car ii overtakes any other car jj inside the tunnel, car ii must be fined. However, each car can be fined at most once.Formally, let's say that car ii definitely overtook car jj if car ii entered the tunnel later than car jj and exited the tunnel earlier than car jj. Then, car ii must be fined if and only if it definitely overtook at least one other car.Find the number of cars that must be fined.

### Input
InputThe first line contains a single integer nn (2≤n≤1052≤n≤105), denoting the number of cars.The second line contains nn integers a1,a2,…,ana1,a2,…,an (1≤ai≤n1≤ai≤n), denoting the ids of cars in order of entering the tunnel. All aiai are pairwise distinct.The third line contains nn integers b1,b2,…,bnb1,b2,…,bn (1≤bi≤n1≤bi≤n), denoting the ids of cars in order of exiting the tunnel. All bibi are pairwise distinct.

### Output
OutputOutput the number of cars to be fined.
NoteThe first example is depicted below:Car 22 definitely overtook car 55, while car 44 definitely overtook cars 11, 22, 33 and 55. Cars 22 and 44 must be fined.In the second example car 55 was definitely overtaken by all other cars.In the third example no car must be fined.
