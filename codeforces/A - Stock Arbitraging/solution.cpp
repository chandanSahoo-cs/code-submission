/*It is not the matter of if, it the matter of when*/
 
#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define int long long
#define ll long long
#define all(x) begin(x), end(x)
void solve()
{
    ll n,m,r; cin>>n>>m>>r;
    vector<ll>s(n);
    vector<ll>b(m);
    for(auto &ele:s) cin>>ele;
    for(auto &ele:b) cin>>ele;
    ll mnS=*min_element(all(s));
    ll mxB=*max_element(all(b));
    if(mxB<mnS) cout<< r <<"\n";
    else{
        cout<<(r/mnS)*mxB+(r-(r/mnS)*mnS)<<"\n";
    }
}
 
int32_t main()
{
    fastio
 
        int T = 1;
    // cin >> T;
 
    while (T--)
        solve();
 
    return 0;
}