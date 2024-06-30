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
        for(ll i=n-1;i>=0;i--){
            if(cnt<store[i]) cnt=store[i];
            else if(store[i]<=cnt ) cnt+=1;
        }
        cout<<cnt<<"\n";
    }
    return 0;
}