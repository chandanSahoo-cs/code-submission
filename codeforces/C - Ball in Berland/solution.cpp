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
  ll a,b,k; cin>>a>>b>>k;
 
  map<ll,ll>mpb,mpg;
 
  vector<pair<ll,ll>>pairs(k);
 
  for(ll i=0;i<k;i++){
    cin>>pairs[i].first;
  }    
 
  for(ll i=0;i<k;i++){
    cin>>pairs[i].second;
  }
 
  vector<vector<ll>>boys(a+1);
 
  for(ll i=0;i<k;i++){
    mpb[pairs[i].first]++;
    mpg[pairs[i].second]++;
 
    boys[pairs[i].first].push_back(pairs[i].second);
  }
 
  ll cnt = 0;
 
  for(ll i=1;i<=a;i++){
    for(auto ele:boys[i]){
      cnt+=k-mpb[i]-mpg[ele]+1;
    }
  }
 
  cout<<cnt/2<<"\n";
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