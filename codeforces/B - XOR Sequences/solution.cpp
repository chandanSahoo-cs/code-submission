#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll tsts; cin >> tsts; while(tsts--)
#define all(x) begin(x), end(x)
 
int main() {
    fastio
    testcases {
        ll x,y; cin>>x>>y;
        ll temp=abs(x-y);
        ll ans;
        for(ll i=1;i<=temp;i*=2){
            if(temp%i==0){
                ans=i;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}