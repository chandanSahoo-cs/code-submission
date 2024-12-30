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
  ll n,p; cin>>n>>p;
  vector<ll>a(n),b(n);
 
  for(auto &ele:a) cin>>ele;  
  for(auto &ele:b) cin>>ele;
 
  vector<pair<ll,ll>>mp;
 
  for(ll i=0;i<n;i++){
    mp.push_back({b[i],a[i]});
  }
 
  sort(all(mp));
 
  vector<ll>ans(n);
  ll j=0;
 
  for(ll i=1;i<n;i++){
    ans[i]=ans[i-1]+mp[j].first;
    mp[j].second--;
    // deb(mp[j].second,j);
    if(mp[j].second==0) j++;
  }
  // deb(ans);
  ll comp = p*n;
 
  for(ll i=1;i<n;i++){
    comp = min(comp,p*(n-i)+ans[i]);
  }
  cout<<comp<<"\n";
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