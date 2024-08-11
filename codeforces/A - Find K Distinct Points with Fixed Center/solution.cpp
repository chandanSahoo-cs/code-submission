/*It is not the matter of if, it is the matter of when*/
/**/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll tsts; cin >> tsts; while(tsts--)
#define all(x) begin(x), end(x)
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
        ll x,y,k; cin>>x>>y>>k;
        set<pair<ll,ll>>coords;
        if(k%2!=0) coords.emplace(x,y);
        ll i=1;
        while(coords.size()<k){
            coords.emplace(x-i,y-i);
            coords.emplace(x+i,y+i);
            i++;
        }
        for(auto ele:coords) cout<<ele.first<<" "<<ele.second<<"\n";
    }
    return 0;
}