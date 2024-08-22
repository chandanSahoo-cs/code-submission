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
    vector<string>store(n);
    for(auto &ele:store) cin>>ele;
    for(ll i=1;i<n-1;i++){
        for(ll j=1;j<n-1;j++){
            if(store[i][j]=='.'){
                if(store[i-1][j]=='.' && store[i+1][j]=='.' && store[i][j-1]=='.' && store[i][j+1]=='.'){
                    store[i-1][j]='#';
                    store[i+1][j]='#';
                    store[i][j-1]='#';
                    store[i][j+1]='#';
                    store[i][j]='#';
                }
            }
        }
    }
    bool flag=true;
    for(ll i = 0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(store[i][j]=='.'){
                flag=false;
                break;
            }
        }
        if(!flag) break;
    }
    if(flag) cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";
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