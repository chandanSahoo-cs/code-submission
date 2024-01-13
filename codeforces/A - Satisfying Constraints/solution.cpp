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
        vector<vector<ll>>cnstrnts(n,vector<ll>(2));
        for(ll i=0;i<n;i++){
            cin>>cnstrnts[i][0];
            cin>>cnstrnts[i][1];
        }
        ll mx=INT_MIN;
        ll mn=INT_MAX;
        vector<ll>ntpssbl;
        for(ll i=0;i<n;i++){
            if(cnstrnts[i][0]==1){
                mx=max(mx,cnstrnts[i][1]);
            }
            if(cnstrnts[i][0]==2){
                mn=min(mn,cnstrnts[i][1]);
            }
            if(cnstrnts[i][0]==3){
                ntpssbl.push_back(cnstrnts[i][1]);
            }
        }
        ll ans=0;
        if(mn-mx<0) ans=0;
        else ans=mn-mx+1;
        for(ll i=0;i<ntpssbl.size();i++){
            if(ans==0) break;
            if(ntpssbl[i]>=mx and ntpssbl[i]<=mn){
                ans-=1;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}