#include <bits/stdc++.h>
using namespace std;
//It is not matter of if, it is matter of when
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll int tsts; cin >> tsts; while(tsts--)
int main() {
    fastio
    testcases {
        ll n,k,mod=1e9+7; cin>>n>>k;
        vector<ll>store(n);
        ll sum=0;
        for(auto &ele:store) {
            cin>>ele;
            sum+=ele;
        }
        for(ll i=1;i<n;i++){
            store[i]=max(store[i],store[i]+store[i-1]);
        }
        ll mx=*max_element(store.begin(),store.end())<0?0:*max_element(store.begin(),store.end());
        for(ll i=0;i<k;i++){
            sum=(sum+mx+mod)%mod;
            mx=(mx+mx+mod)%mod;
        }
        sum=(sum+mod)%mod;
        cout<<sum<<"\n";
    }
    return 0;
}