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
 
bool check(ll l1, ll r1, ll l2, ll r2){
  if((r1>=l2 && l1<=r2) || (r2>=l1 && l2<=r1)) return true;
  return false;
}
 
bool compute(vector<pair<ll,ll>>&a, ll m){
  ll l=0, r =0;
 
  for(auto &[x,y]:a){
    if(check(max(0LL,l-m),r+m,x,y)){
      l=max(x,max(0LL,l-m)) ,r=min(r+m,y);
    }else return false;
  }
 
  return true;
}
 
void realmsDomain(){
  ll n; cin>>n;
  vector<pair<ll,ll>>a(n);
  ll mx = 0;
 
  for(auto &ele:a){ 
    cin>>ele.first>>ele.second;
    mx = max(ele.first,mx);
    mx = max(ele.second,mx);
  }
 
  ll l = 0, r = mx;
  ll ans = r;
 
  while(l<=r){
    ll m = l+(r-l)/2;
 
    if(compute(a,m)){
      ans = m;
      r = m-1;
    }else l=m+1;
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