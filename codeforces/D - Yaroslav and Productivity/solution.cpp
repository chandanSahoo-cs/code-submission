/*It is happening, right here and now*/
        
#include "bits/stdc++.h"
using namespace std;
 
#define velociraptor ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);                                             
#define all(v) v.begin(),v.end()
#define lcd(a,b) a*(b/__gcd(a,b))
#define ll long long
 
const int mod = 1e9+7;
 
#ifdef chandan  
#include "starPlatinum.h"
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif
 
ll dp[200005][2];
 
ll rec(vector<ll>&pref, vector<ll>&b, ll i, ll sign){
    ll n = pref.size(), m = b.size();
 
    if(i>=m) return 0;
 
    if(dp[i][sign]!=-1) return dp[i][sign];
 
    // not_pick
    ll p1 = rec(pref,b,i+1,sign);
 
    // pick
    ll p2 = (!sign?-2*pref[b[i]]:2*pref[b[i]]) + rec(pref,b,i+1,!sign);
 
    return dp[i][sign] = max(p1,p2);
}
 
void realmsDomain(){
  ll n,m; cin>>n>>m;
  vector<ll>a(n),b(m);
 
  for(auto &ele:a) cin>>ele;
  for(auto &ele:b) cin>>ele;
 
  sort(all(b),greater());  
 
  vector<ll>pref(n+1);
  
  for(ll i=1;i<=n;i++){
    pref[i] = a[i-1]+pref[i-1];
  }
  deb(pref);
 
  for(ll i=0;i<=m;i++){
    dp[i][0] = dp[i][1]= -1;
  }
 
  ll ans = pref[n];
 
  cout<<pref[n]+rec(pref,b,0,0)<<"\n";
}
 
int main() {
    clock_t time_req = clock();
    velociraptor
 
 
    #ifdef chandan 
    freopen("error.txt", "w", stderr); 
    #endif
 
    ll tsts = 1 ; 
 
    cin>>tsts;    
 
    for(ll testcase = 1 ; testcase <=  tsts ; testcase++ ){
        realmsDomain();
    }
 
    #ifdef chandan
    cerr << "Time : " << fixed << setprecision(6) << ((double)(clock() - time_req)) / CLOCKS_PER_SEC << endl;
    #endif
 
    return 0;
}