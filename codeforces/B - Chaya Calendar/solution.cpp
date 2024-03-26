#include <bits/stdc++.h>
using namespace std;
//It is not matter of if, it is matter of when
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll int tsts; cin >> tsts; while(tsts--)
int main() {
    fastio
    testcases {
        ll n; cin>>n; vector<ll>store(n); for(auto &ele:store) cin>>ele; for(ll i=1;i<n;i++) if(store[i-1]>=store[i]) store[i]=store[i]*((store[i-1]/store[i])+1); cout<<store[n-1]<<"\n";
    }
    return 0;
}