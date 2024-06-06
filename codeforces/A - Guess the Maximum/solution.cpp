#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll tsts; cin >> tsts; while(tsts--)
#define all(x) begin(x), end(x)
 
int main() {
    fastio
    testcases {
        ll n; cin>>n;
        vector<ll>store(n);
        for(auto &ele:store) cin>>ele;
        ll ans=INT_MAX;
        for(ll i=0;i<n-1;i++){
            ll temp=max(store[i],store[i+1]);
            ans=min(temp,ans);
        }
        cout<<ans-1<<"\n";
    }
    return 0;
}