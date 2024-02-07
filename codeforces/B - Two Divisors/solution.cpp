#include <bits/stdc++.h>
using namespace std;
//It is not matter of if, it is matter of when
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll int tsts; cin >> tsts; while(tsts--)
int main() {
    fastio
    testcases {
        ll a,b; cin>>a>>b;
        ll lcm=(a*b)/__gcd(a,b);
        if(lcm>b) cout<<lcm<<"\n";
        else cout<<lcm*(b/a)<<"\n";
    }
    return 0;
}