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
        ll cnt=0;
        ll waves=0;
        for(ll i=1;i<n;i++){
            if(store[i]<store[i-1]){
                cnt+=(store[i-1]-store[i]);
                waves=max(waves,store[i-1]-store[i]);
                store[i]=store[i-1];
            }
        }
        cout<<cnt+waves<<"\n";
    }
    return 0;
}