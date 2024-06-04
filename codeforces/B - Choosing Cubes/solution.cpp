//**It is not matter of if, it is matter of when
 
#include <bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#include "chandan/skills.h"
#define deb(x...)                 \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define deb(x...)
#endif
 
#define ll long long
#define all(x) begin(x), end(x)
void solve()
{
    ll n,f,k; cin>>n>>f>>k;
    vector<ll>store(n);
    for(auto &ele:store) cin>>ele;
    ll fav=store[f-1];
    vector<ll>freq(*max_element(all(store))+1,0);
    for(ll i=0;i<n;i++){
        freq[store[i]]++;
    }
    for(ll i=freq.size()-1;i>=0;i--){
        if(i==fav){
            if(k<=0) cout<<"NO"<<"\n";
            else if(k-freq[i]>=0) cout<<"YES"<<"\n";
            else if(k-freq[i]<0) cout<<"MAYBE"<<"\n";
            break;
        }
        k-=freq[i];
    }
}
 
int main()
{
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("onlineJudge/input.txt", "r", stdin);
    freopen("onlineJudge/error.txt", "w", stderr);
    freopen("onlineJudge/output.txt", "w", stdout);
#endif
    int tt;
    cin >> tt;
 
    while (tt--)
    {
        solve();
    }
 
    return 0;
}