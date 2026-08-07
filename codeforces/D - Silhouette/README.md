# [D. Silhouette](https://codeforces.com/contest/2254/problem/D)

---
Yousef has a secret array a of n strictly positive integers.For each element ai, its shadow bi is the sum of all elements in a that are strictly smaller than ai. Formally:bi=∑1≤j≤naj<aiajYou are given the shadow array b. Your task is to reconstruct the lexicographically smallest valid array a consisting of strictly positive integers that satisfies the above condition. If no such array exists, output −1.

### Input
InputThe first line contains an integer t (1≤t≤104) — the number of test cases.The first line of each test case contains an integer n (1≤n≤2⋅105) — the size of the array.The second line of each test case contains n integers b1,b2,…,bn (0≤bi≤2⋅1014) — the shadow array.It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

### Output
OutputFor each test case, output n integers a1,a2,…,an (1≤ai≤1018) — the lexicographically smallest valid array a that satisfies the condition. If no valid array exists, output −1 instead.
NoteIn the first test case, the answer is a=[1]. Since there is only one element, there are no strictly smaller elements, so its shadow is 0. Thus a=[1] is valid. It is also lexicographically smallest, because the only allowed values are positive integers, and 1 is the smallest possible.In the second test case, the answer is a=[2,5,2,5,6]:  For each 2, there is no smaller element in the array, so the shadow is 0.  For each 5, the strictly smaller elements are the two 2's, so the shadow is 2+2=4.  For 6, the strictly smaller elements are two 2's and two 5's, so the shadow is 2+2+5+5=14. Therefore the shadow array is exactly b=[0,4,0,4,14].In the third test case, the shadow array for a=[3,2,2] is calculated as follows:  For a1=3, the strictly smaller elements in the array are the two 2s. Their sum is 2+2=4. So, b1=4.  For a2=2, there are no strictly smaller elements in the array. So, b2=0.  For a3=2, there are no strictly smaller elements in the array. So, b3=0. The resulting shadow array is b=[4,0,0], which matches the input.
