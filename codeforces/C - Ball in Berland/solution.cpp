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
  vector<ll>boys(k),girls(k);
  map<ll,ll>mpb, mpg;
 
  for(auto &ele:boys) cin>>ele;
  for(auto &ele:girls) cin>>ele;
 
 
  for(ll i=0;i<k;i++){
    mpb[boys[i]]++;
    mpg[girls[i]]++;
  }
 
  ll cnt = 0;
 
  for(ll i=0;i<k;i++){
    cnt+=k-(mpb[boys[i]]+mpg[girls[i]]-1);
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