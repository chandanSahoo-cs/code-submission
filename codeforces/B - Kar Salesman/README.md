# [B. Kar Salesman](https://codeforces.com/contest/2022/problem/B)

---
Karel is a salesman in a car dealership. The dealership has n different models of cars. There are ai cars of the i-th model. Karel is an excellent salesperson and can convince customers to buy up to x cars (of Karel's choice), as long as the cars are from different models.Determine the minimum number of customers Karel has to bring in to sell all the cars.

### Input
InputEach test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows.The first line of each test case contains two integers n and x (1≤n≤5⋅105; 1≤x≤10) — the number of different models of cars and the maximum number of cars Karel can convince a customer to buy.The second line contains n integers a1,a2,…,an (1≤ai≤109) — the number of cars of each model.It is guaranteed that the sum of n over all test cases does not exceed 5⋅105.

### Output
OutputFor each test case, output the minimum possible number of customers needed to sell all the cars.
NoteFor the first case, Karel only needs to lure in 3 customers. He will convince the customers to buy the following models of cars:   Customer 1 buys 2 cars with model 1 and 3.  Customer 2 buys 2 cars with model 1 and 2.  Customer 3 buys 2 cars with model 1 and 3. For the second case, Karel only needs to lure in 3 customers. He will convince the customers to buy the following models of cars:   Customer 1 buys 2 cars with model 1 and 3.  Customer 2 buys 3 cars with model 1, 2 and 3.  Customer 3 buys 1 car with model 3.
