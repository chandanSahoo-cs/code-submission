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
 
void Sieve(vector<ll>&v,vector<ll>&a){
  ll n = v.size();
  ll k = a.size();
 
  for(ll i=0;i<k;i++){
    v[a[i]] = a[i];
  }
 
  for(ll i=0;i<n;i++){
    if(v[i]==0) continue;
    for(ll j=2*i;j<n;j+=i){
      if(v[j]==0) break;
      if(v[j]<i) continue;
      v[j] = i; 
    }
  }
  deb(v);
  return;
}
 
void realmsDomain(){
  ll n; cin>>n;
  string s; cin>>s;
  vector<ll>a;
 
  for(ll i=0;i<n;i++){
    if(s[i]=='0') a.push_back(i+1);
  }
 
  vector<ll>partSieve(n+1);
  Sieve(partSieve,a);
 
  ll ans = 0;
  deb(a);
  for(ll i=0;i<(ll)a.size();i++){
    ans+=partSieve[a[i]];
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