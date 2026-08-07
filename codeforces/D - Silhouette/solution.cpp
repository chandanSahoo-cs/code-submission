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
  vector<ll>b(n);
  map<ll,ll>mp;
 
  for(auto &ele:b){
    cin>>ele;
    mp[ele]++;
  }
 
  vector<pair<ll,ll>>c;
 
  for(auto &[key,value]:mp){
    c.push_back({key,value});
  }
 
  ll m = c.size();
 
  if(c[0].first!=0){
    cout<<"-1\n";
    return;
  }
 
  vector<ll>values;
  ll prev = 0;
 
  for(ll i=0;i<m-1;i++){
    auto [sub,req] = c[i];
    auto [want,_] = c[i+1];
 
    ll curr = want-sub;
 
    if(curr%req!=0 || curr/req<=prev){
      cout<<"-1\n";
      return;
    }
    prev = curr/req;
 
    for(ll j=0;j<req;j++){
      values.push_back(prev);
    }
  }
 
  for(ll j=0;j<c[m-1].second;j++){
    values.push_back(prev+1);
  }
 
  vector<ll>foo(n);
  iota(all(foo),0);
 
  sort(all(foo),[&](ll i, ll j){
    return b[i]<b[j];
  });
 
  vector<ll>a(n);
 
  for(ll i=0;i<n;i++){
    a[foo[i]] = values[i];
  }
 
  for(ll i=0;i<n;i++){
    cout<<a[i]<<" \n"[i==n-1];
  }
 
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