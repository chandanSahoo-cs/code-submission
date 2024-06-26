#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define all(x) begin(x), end(x)
int main() {
    fastio
        ll n; cin>>n;
        vector<ll>x(n);
        for(auto &ele:x) cin>>ele;
        sort(all(x));
        ll q; cin>>q;
        vector<ll>m(q);
        for(auto &ele:m) cin>>ele;
        vector<ll>a;
        for(ll i=0;i<q;i++){
            ll s=0,e=n-1;
            ll t=m[i];
            ll ans=0;
            while(s<=e){
                ll mid=s+(e-s)/2;
                if(x[mid]<=t){
                    s=mid+1;
                    ans=mid+1;
                }
                else e=mid-1;
            }
            a.push_back(ans);
        }
        for(auto ele:a) cout<<ele<<"\n";
}