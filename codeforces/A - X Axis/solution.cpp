#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll tsts; cin >> tsts; while(tsts--)
#define all(x) begin(x), end(x)
int main() {
    fastio
    testcases {
        ll a,b,c; cin>>a>>b>>c;
        ll t1=abs(a-a)+abs(a-b)+abs(a-c);
        ll t2=abs(a-b)+abs(b-b)+abs(b-c);
        ll t3=abs(c-a)+abs(c-b)+abs(c-c);
        cout<<min(t1,min(t2,t3))<<"\n";
    }
    return 0;
}