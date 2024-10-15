#include "bits/stdc++.h"
using namespace std;
 
#define velociraptor ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(v) v.begin(),v.end()
#define lcd(a,b) a*(b/__gcd(a,b))
#define ll long long
 
void realmsDomain(){
    ll n;cin>>n;
    vector<ll>a(n);
    for(auto &ele:a) cin>>ele;
    for(ll k=n;k>=0;k--){
        multiset<ll>mst(all(a));
        ll i=1;
        ll t=0;
        while(!mst.empty()){
            ll cmp = k-i+1;
            auto it = upper_bound(all(mst),cmp);
            --it;
            ll val = *(it);
            if(val<=cmp && !mst.empty()){
                mst.extract(val);
                if(!mst.empty()){
                    mst.extract(*(mst.begin()));
                    i++;
                }
                t++;
            }
            else break;
        }
        if(t==k){
            cout<<k<<"\n";
            return;
        }
    }
    cout<<0<<"\n";
}
 
int main() {
    velociraptor
    ll tsts = 1 ; cin>>tsts;
    for(ll testcase = 1 ; testcase <=  tsts ; testcase++ ){
        realmsDomain();
    }
    return 0;
}