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
    ll n,m; cin>>n>>m;
    string s; cin>>s;
    vector<ll>ques(7,0);
    for(ll i=0;i<n;i++){
        ques[s[i]-65]++;
    }
    ll cnt=0;
    for(ll i=0;i<7;i++){
        cnt+=m>=ques[i]?m-ques[i]:0;
    }
    cout<<cnt<<"\n";
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