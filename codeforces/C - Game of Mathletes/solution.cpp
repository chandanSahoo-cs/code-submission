/*It is not the matter of if, it is the matter of when*/
        
#include "bits/stdc++.h"
using namespace std;
 
#define velociraptor ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);                                             
#define all(v) v.begin(),v.end()
#define lcd(a,b) (a*b)/__gcd(a,b)
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
  map<ll,ll>mp;
  vector<ll>a(n);
  for(auto &ele:a) cin>>ele,mp[ele]++;
 
  vector<ll>mark(n+1);
  ll ans = 0;
  deb(mp);
  for(auto ele:mp){
    auto it = mp.find(k-ele.first);
    if(mark[ele.first] || mark[it->first]) continue;
    if(it==mp.end()) continue;
    if(it->first==ele.first) ans+=ele.second/2;
    else ans+=min(ele.second,it->second);
    mark[ele.first]=1;
    mark[it->first]=1;
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