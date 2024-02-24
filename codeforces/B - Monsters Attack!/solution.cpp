#include <bits/stdc++.h>
using namespace std;
//It is not matter of if, it is matter of when
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll int tsts; cin >> tsts; while(tsts--)
int main() {
    fastio
    testcases {
        ll n,k; cin>>n>>k;
        vector<ll>hlth(n);
        for(auto &ele:hlth) cin>>ele;
        vector<ll>pts(n);
        for(auto &ele:pts){
            cin>>ele;
            ele=abs(ele);
        }
        ll mx=*max_element(pts.begin(),pts.end());
        vector<ll>freq(mx+1);
        for(ll i=0;i<n;i++){
            freq[pts[i]]+=hlth[i];
        }
        ll tStore=0;
        bool flag=true;
        for(ll i=1;i<mx+1;i++){
            freq[i]-=k-tStore;
            tStore=freq[i];
            if(tStore>0){
                flag=false;
                break;
            }
        }
        if(flag) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
    return 0;
}