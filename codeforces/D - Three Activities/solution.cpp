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
 
vector<pair<ll,ll>>give(vector<ll>&a){
  ll n = a.size();
  pair<ll,ll> mx1 = {-1,-1}, mx2 = {-1,-1}, mx3 = {-1,-1};
 
  for(ll i=0;i<n;i++){
    if(a[i]>=mx1.first){
      mx3 = mx2;
      mx2 = mx1;
      mx1 = {a[i],i};
    }else if(a[i]>=mx2.first){
      mx3 = mx2;
      mx2 = {a[i],i};
    }else if(a[i]>mx3.first){
      mx3 = {a[i],i};
    }
  }
 
  return {mx1,mx2,mx3};
}
 
void realmsDomain(){
  ll n; cin>>n;
  vector<ll>a(n),b(n),c(n);
 
  for(auto &ele:a) cin>>ele;
  for(auto &ele:b) cin>>ele;
  for(auto &ele:c) cin>>ele;
 
  vector<pair<ll,ll>>mxa = give(a);
  vector<pair<ll,ll>>mxb = give(b);
  vector<pair<ll,ll>>mxc = give(c);
 
  ll mx = 0;
 
  for(ll i=0;i<3;i++){
    for(ll j=0;j<3;j++){
      for(ll k=0;k<3;k++){
        if(mxa[i].second==mxb[j].second || mxb[j].second==mxc[k].second || mxa[i].second==mxc[k].second) continue;
        mx = max(mx,mxa[i].first+mxb[j].first+mxc[k].first);
      }
    }
  }
 
  cout<<mx<<"\n";
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