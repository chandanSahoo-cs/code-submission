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
ll ops(ll n){
    ll cnt=0;
    while(n>0){
        n/=3;
        cnt++;
    }
    return cnt;
}
int main() {
    fastio
    ll MAX=2e5+1;
    vector<ll>store(MAX);
    for(ll i=1;i<MAX;i++){
        store[i]=ops(i);
        store[i]+=store[i-1];
    }
    testcases {
        ll l,r;cin>>l>>r;
        cout<<(store[r]-store[l-1])+store[l]-store[l-1]<<"\n";
    }
    return 0;
}