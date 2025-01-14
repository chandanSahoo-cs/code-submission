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
 
void realmsDomain(){
  ll n,k; cin>>n>>k;
  vector<ll>a(n);
  for(auto &ele:a) cin>>ele;
 
  ll ele = a[0];
 
  map<ll,ll>mp;
  mp[ele] = ele;
  for(ll i=1;i<n;i++){
    if(ele>=a[i]){
      mp[ele]+=a[i];
    }
    else{
      mp[a[i]] = a[i]+mp[ele];
      ele = a[i];
    }
  }
 
  deb(mp);
 
  for(ll i=0;i<k;i++){
    ll j; cin>>j;
    auto it = mp.upper_bound(j);
    if(it==mp.begin()){
      cout<<0<<" \n"[i==k-1];
      continue;
    }
    it--;
    cout<<(*it).second<<" \n"[i==k-1];
  }
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