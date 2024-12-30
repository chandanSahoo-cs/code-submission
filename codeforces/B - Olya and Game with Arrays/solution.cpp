/*It is not the matter of if, it is the matter of when*/
        
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
My idea : 
-> Find the lowest two element from the each element
-> Find the minmum amongst this array of pair
-> Then test for each case i.e. get the total sum of all second lowest element and then
  subtract second lowest element of each array from this sum and add min
  and stores its max
*/
void realmsDomain(){
  ll n; cin>>n;
  vector<pair<ll,ll>>vp;
 
  for(ll i=0;i<n;i++){
    ll m; cin>>m;
    ll m1= mod;
    ll m2= mod;
 
    for(ll j=0;j<m;j++){
      ll ele;cin>>ele;
      if(ele<=m1){
        m2 = min(m1,m2);
        m1 = min(m1,ele);
      }
      else if(ele<=m2){
        m2 = min(m2,ele);
      }
    }
    vp.push_back({m1,m2});
  }
 
  ll sum=0;
  ll mn = mod;
  for(ll i=0;i<n;i++){
    sum+=vp[i].second;
    mn = min(mn,vp[i].first);
  }
 
  ll ans = -1;
 
  for(ll i=0;i<n;i++){
    ans = max(ans,sum-vp[i].second+mn);
  }
 
  cout<<ans<<"\n";
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