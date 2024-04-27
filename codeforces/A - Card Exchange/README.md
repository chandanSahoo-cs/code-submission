# [A. Card Exchange](https://codeforces.com/contest/1966/problem/A)

---
You have a hand of nn cards, where each card has a number written on it, and a fixed integer kk. You can perform the following operation any number of times:  Choose any kk cards from your hand that all have the same number.  Exchange these cards for k−1k−1 cards, each of which can have any number you choose (including the number written on the cards you just exchanged). Here is one possible sequence of operations for the first example case, which has k=3k=3:  What is the minimum number of cards you can have in your hand at the end of this process?

### Input
InputThe first line of the input contains a single integer tt (1≤t≤5001≤t≤500) — the number of test cases. The description of the test cases follows.The first line of each test case contains two integers nn and kk (1≤n≤1001≤n≤100, 2≤k≤1002≤k≤100) — the number of cards you have, and the number of cards you exchange during each operation, respectively.The next line of each test case contains nn integers c1,c2,…cnc1,c2,…cn (1≤ci≤1001≤ci≤100) — the numbers written on your cards.

### Output
OutputFor each test case, output a single integer — the minimum number of cards you can have left in your hand after any number of operations.
NoteThe first example case corresponds to the picture above. The sequence of operations displayed there is optimal, so the answer is 22.In the second example case, no operations can be performed, so the answer is 11.In the fourth example case, you can repeatedly select 44 cards numbered with 11 and replace them with 33 cards numbered with 11, until there are 33 cards left.
