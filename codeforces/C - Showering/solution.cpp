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
        ll n,s,m; cin>>n>>s>>m;
        vector<pair<ll,ll>>store;
        for(ll i=0;i<n;i++){
            ll l,r; cin>>l>>r;
            store.push_back({l,r});
        }
        bool flag=false;
        ll start=0;
        for(ll i=0;i<n;i++){
            if(store[i].first-start>=s){
                flag=true;
                break;
            }
            else{
                start=store[i].second;
            }
        }
        if(flag){
            cout<<"YES"<<"\n";
        }
        else{
            if(m-start>=s){
                cout<<"YES"<<"\n";
            }
            else cout<<"NO"<<"\n";
        }
    }
    return 0;
}