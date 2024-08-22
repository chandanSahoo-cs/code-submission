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
    ll n; cin>>n;
    vector<ll>store(n);
    for(auto &ele:store) cin>>ele;
    // sort(all(store));
    // for(auto ele:store) cout<<ele<<" ";
    // cout<<"\n";
    map<ll,ll>mp;
    for(auto ele:store) mp[ele]++;
    bool flag=true;
    if(mp[2]){
        cout<<2<<" ";
        mp[2]--;
    }
    if(mp[1]){
        cout<<1<<" ";
        mp[1]--;
    }
    while(mp[1]>0 || mp[2]>0){
        if(mp[2]){
            cout<<2<<" ";
            mp[2]--;
        }
        else if(mp[1]){
            cout<< 1 <<" ";
            mp[1]--;
        }
    }
    cout<<"\n";
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