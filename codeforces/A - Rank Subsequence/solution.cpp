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
 
void realmsDomain(){
  ll n; cin>>n;
  vector<tuple<ll,ll,ll,ll>>a;
 
  for(ll i=0;i<n;i++){
    ll l,r,u,v; cin>>l>>r>>u>>v;
    a.push_back({l,r,u,v});
  }
 
  for(ll i=n;i>=1;i--){
    ll idx = 0;
 
    for(ll j=0;j<n && idx<i;j++){
      ll lrank = idx+1, rrank = i-idx;
      auto [l,r,u,v] = a[j];
      if((lrank<l || lrank>r) && (rrank<u || rrank>v)) idx++; 
    }
 
    if(idx==i){
      cout<<i<<"\n";
      return;
    }
  } 
 
  cout<<0<<"\n";
  return; 
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