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
        ll n; cin>>n;
        vector<ll>perm(n);
        for(auto &ele:perm) cin>>ele;
        for(ll i=0;i<n;i++){
            if(perm[i]==n) perm[i]=1;
            else perm[i]+=1;
        }
        for(auto ele:perm) cout<<ele<<" ";
        cout<<"\n";
    }
    return 0;
}