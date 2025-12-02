/*It is happening, right here and now*/
        
#include "bits/stdc++.h"
using namespace std;
 
#define velociraptor ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);                                             
#define all(v) v.begin(),v.end()
#define lcd(a,b) (a*b)/__gcd(a,b)
#define ll long long
 
const int mod = 1e9+7;
 
#ifdef chandan  
#include "starPlatinum.h"
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif
 
ll dp[200005][28];
 
ll rec(ll n, string &s, ll i,ll prev){
    if(i==n) return 0;
    if(dp[i][prev]!=-1) return dp[i][prev];
 
    if(prev!=s[i]) return dp[i][prev] = rec(n,s,i+1,s[i]);
 
    ll mn=LLONG_MAX;
 
    for(char c='a';c<='z';c++){
        if(prev==c) continue;
        mn = min(mn,1+rec(n,s,i+1,c));
    }
 
    return dp[i][prev]=mn;
}
 
void give(ll n, string &s, ll i,ll prev,string &ans ){
    if(i==n) return;
 
    if(prev!=s[i]){
        ans.push_back(s[i]);
        give(n,s,i+1,s[i],ans);
        return;
    } 
 
    ll mn=LLONG_MAX;
    char k=s[i];
    for(char c='a';c<='z';c++){
        if(prev==c) continue;
        ll t = rec(n,s,i+1,c);
        if(mn>t){
            mn = t;
            k = c;
        }
    }
    ans.push_back(k);
    give(n,s,i+1,k,ans);
}
 
void realmsDomain(){
    string s; cin>>s;
    ll n = s.size();
    memset(dp,-1,sizeof(dp));
 
    string ans="";
    give(n,s,0,27,ans);
    cout<<ans<<"\n";
}
 
int main() {
    clock_t time_req = clock();
    velociraptor
 
 
    #ifdef chandan 
    freopen("error.txt", "w", stderr); 
    #endif
 
    ll tsts = 1 ; 
 
    // cin>>tsts;    
 
    for(ll testcase = 1 ; testcase <=  tsts ; testcase++ ){
        realmsDomain();
    }
 
    #ifdef chandan
    cerr << "Time : " << fixed << setprecision(6) << ((double)(clock() - time_req)) / CLOCKS_PER_SEC << endl;
    #endif
 
    return 0;
}