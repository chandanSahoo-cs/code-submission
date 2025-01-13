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
 
void makeMax(ll &mx1, ll &mx2 ,ll val){
  if(val>=mx1){
    mx2 = mx1;
    mx1 = val;
  }
  else if(val>=mx2){
    mx2 = val;
  }
  return;
}
 
ll val(ll a){
  return a - (a+1)/2;
}
 
void realmsDomain(){
  ll n,k; cin>>n>>k;
  vector<vector<ll>>mp(k);  
  
  for(ll i=0;i<n;i++){
    ll ele; cin>>ele;
    ele--;
    if(mp[ele].empty()){
      mp[ele].push_back(0);
    }
    mp[ele].push_back(i+1);
  }
 
  deb(mp);
 
  for(auto &ele:mp){
    ele.push_back(n+1);
  }
 
  ll ans=LLONG_MAX;
  for(auto ele:mp){
    if(ele.size()==1) continue;
    ll mx1=-1,mx2=-1;
    for(ll i=1;i<(ll)ele.size();i++){
      makeMax(mx1,mx2,ele[i]-ele[i-1]-1);
    }
    ans = min(ans,max(mx2,val(mx1)));
    deb(ans,ele.size());
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