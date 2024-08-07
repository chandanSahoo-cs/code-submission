/*It is not the matter of if, it is the matter of when*/
/**/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll tsts; cin >> tsts; while(tsts--)
#define all(x) begin(x), end(x)
// #define push_back(x) emplace_back(x);
#define push(x) emplace(x);
#define insert(x) emplace(x);
int main() {
    fastio
    testcases {
        ll a1,a2,b1,b2; cin>>a1>>a2>>b1>>b2;
        ll sum=0;
        if(a1>b1 && a2>=b2) sum++;
        else if (a1==b1 && a2>b2) sum++;
        if(a1>b2 && a2>=b1) sum++;
        else if(a1==b2 && a2>b1) sum++;
        if(a2>b2 && a1>=b1) sum++;
        else if(a2==b2 && a1>b1) sum++;
        if(a2>b1 && a1>=b2) sum++;
        else if(a2==b1 && a1>b2) sum++;
        cout<<sum<<"\n";
    }
    return 0;
}