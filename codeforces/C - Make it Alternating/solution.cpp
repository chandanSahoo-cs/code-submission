/*It is not the matter of if, it is the matter of when*/
        
#include "bits/stdc++.h"
using namespace std;
 
#define velociraptor ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);                                             
#define all(v) v.begin(),v.end()
#define lcd(a,b) a*(b/__gcd(a,b))
#define ll long long
 
const int mod = 998244353;
 
#ifdef chandan  
#include "starPlatinum.h"
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif
 
ll fact(ll n){
  if(n==0) return 1;
  ll ans=1;
  for(ll i=1;i<=n;i++){
    ans = (ans*i)%mod;
  }
  return ans;
}
 
 
void realmsDomain(){
  string s; cin>>s;
  ll n = s.size();
 
  ll curr=1;
  ll ways=1;
  ll cnt=0;
 
  for(ll i=1;i<n;i++){
    if(s[i]!=s[i-1]){
      ways=(ways*curr)%mod;
      curr=1;
      cnt++;
    }else curr++;
  }
 
  cnt++;
  ways=(ways*curr)%mod;
  deb(n-cnt,ways);
  ll ans = (ways*fact(n-cnt))%mod;
 
  cout<<n-cnt<<" "<<ans<<"\n";
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