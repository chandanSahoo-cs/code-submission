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
ll ask(ll a,ll b){
    cout<<"?"<<" "<<a<<" "<<b<<endl;
    ll area; cin>>area;
    return area;
}
void ans(ll ans){
    cout<<"! "<<ans<<endl;
}
int main() {
    fastio
    testcases {
        ll s=2,e=999;
        ll store;
        while(s<=e){
            ll m=s+(e-s)/2;
            if(m==ask(1,m)) s=m+1;
            else{
                store=m;
                e=m-1;
            }
        }
        ans(store);
    }
    return 0;
}