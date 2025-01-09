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
  ll n; cin>>n;
  set<ll>st;
  map<ll,ll>mp;
  for(ll i=0;i<n;i++){
    ll ele; cin>>ele;
    st.insert(ele);
    mp[ele]=i+1;
  }
  deb(mp);
  vector<ll>a;
  a.assign(st.begin(),st.end());
 
  ll mx = -1;
  for(ll i=0;i<(ll)a.size();i++){
    for(ll j=i;j<(ll)a.size();j++){
      if(__gcd(a[i],a[j])==1){
        mx = max(mx,mp[a[i]]+mp[a[j]]);
      }
    }
  }
 
  cout<<mx<<"\n";
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