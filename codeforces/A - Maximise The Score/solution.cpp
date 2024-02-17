#include <bits/stdc++.h>
using namespace std;
//It is not matter of if, it is matter of when
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll int tsts; cin >> tsts; while(tsts--)
int main() {
    fastio
    testcases {
        ll n; cin>>n;
        vector<ll>store((2*n));
        for(auto &ele:store){
            cin>>ele;
        }
        sort(store.begin(),store.end());
        ll ans=0;
        for(ll i=0;i<2*n;i+=2){
            ans+=store[i];
        }
        cout<<ans<<"\n";
    }
    return 0;
}