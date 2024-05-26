//**It is not matter of if, it is matter of when
 
#include<bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#include "chandan/skills.h"
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif
 
#define ll long long
#define all(x) begin(x), end(x)
void solve() {
    ll n,m; cin>>n>>m;
    if(n>=m){
        if(n%2==0 && m%2==0) cout<<"YES\n";
        else if(n%2!=0 && m%2!=0) cout<<"YES\n";
        else cout<<"NO\n";
    }
    else cout<<"NO\n";
}
 
 
int main() {
 
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("onlineJudge/input.txt", "r", stdin);
        freopen("onlineJudge/error.txt", "w", stderr); 
        freopen("onlineJudge/output.txt", "w", stdout);
    #endif
    int tt;
    cin >> tt;
    
    while (tt--) {
        solve();
    }
 
    return 0;
}