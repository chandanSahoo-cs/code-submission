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
            ll n; cin>>n;
        vector<ll>store(n);
        for(auto &ele:store) cin>>ele;
        sort(all(store));
        ll frst=store[0],scnd;
        for(ll i=0;i<n;i++){
            if(store[i]%frst!=0){
                scnd=store[i];
                break;
            }
        }
        bool flag=true;
        for(ll i=0;i<n;i++){
            if(store[i]%frst!=0 && store[i]%scnd!=0){
                flag=false; 
                break;
            }
        }
        if(flag) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
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