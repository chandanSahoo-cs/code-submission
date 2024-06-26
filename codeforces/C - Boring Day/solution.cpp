#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll tsts; cin >> tsts; while(tsts--)
#define all(x) begin(x), end(x)
int main() {
    fastio
    testcases {
        ll n,l,r; cin>>n>>l>>r;
        vector<ll>store(n);
        for(auto &ele:store) cin>>ele;
        ll pl=-1,pr=0;
        ll cnt=0;
        ll ans=0;
        bool flag=false;
        while(pl<=pr &&  pr!=n){
            if(flag) cnt-=store[pl];
            else cnt+=store[pr];
            if(cnt<l){
                pr++;
                flag=false;
            }
            else if(cnt>r){
                pl++;
                flag=true;
            }
            else{
                ans++;
                pl=pr;
                cnt=0;
                pr++;
                flag=false;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}