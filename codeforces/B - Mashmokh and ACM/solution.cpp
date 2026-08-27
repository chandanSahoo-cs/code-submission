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
 
/*
so we can have a dp[20005][20005]
and for each iteration we will have n/2000 values
*/
 
void realmsDomain(){
  ll n,k; cin>>n>>k;
 
  vector<ll>curr(n+1),next(n+1,1);
 
  for(ll j=k-2;j>=0;j--){
    for(ll i=n;i>=1;i--){
      curr[i] = 0;  
      for(ll l=1;l<=n;l++){
        if(i*l>n) break;
        curr[i] = (curr[i]+next[l*i])%mod;
      }
    }
    next = curr;
  }
 
  ll cnt = 0;
 
  for(ll i=1;i<=n;i++){
    cnt = (cnt+next[i])%mod;
  }
 
  cout<<cnt<<"\n";
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