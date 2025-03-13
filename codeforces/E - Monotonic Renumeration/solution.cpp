/*It is not the matter of if, it is the matter of when*/
        
#include "bits/stdc++.h"
using namespace std;
 
#define velociraptor ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);                                             
#define all(v) v.begin(),v.end()
#define lcd(a,b) (a*b)/__gcd(a,b)
#define ll long long
 
const int mod = 998244353;
 
#ifdef chandan  
#include "starPlatinum.h"
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif
 
 
void realmsDomain(){
  ll n; cin>>n;
  vector<ll>a(n);
  for(auto &ele:a) cin>>ele;
 
  map<ll,pair<ll,ll>> mp;
 
  for(ll i=0;i<n;i++){
    if(mp.find(a[i])!=mp.end()){
        mp[a[i]].second=i;
    }
    else{
        mp[a[i]] = {i,i};
    }
  }
 
  vector<pair<ll,ll>>vp;
 
  for(auto ele:mp){
    vp.push_back(ele.second);
  }
  ll ans = 1;
  ll last=1;
 
  for(auto ele:a){
    if(mp[ele].first<last){
        ans = ans*1;
    }
    else{
        ans = (ans*2)%mod;
    }
    last=max(last,mp[ele].second);
    deb(ele);
    deb(ans,last);
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
 
    // cin>>tsts;    
 
    for(ll testcase = 1 ; testcase <=  tsts ; testcase++ ){
        realmsDomain();
    }
 
    #ifdef chandan
    cerr << "Time : " << fixed << setprecision(6) << ((double)(clock() - time_req)) / CLOCKS_PER_SEC << endl;
    #endif
 
    return 0;
}