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
 
ll binExpMod(ll base, ll exp) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
 
ll modMul(ll n,ll m){
    return (n*m)%mod;
}
 
ll modSum(ll n,ll m){
    return (n+m)%mod;
}
 
ll fact(ll n){
    ll ans = 1;
    for(ll i=1;i<n+1;i++){
        ans = modMul(ans,i);
    }
    return ans;
}
 
ll invFact(ll n){
    return binExpMod(fact(n),mod-2)%mod;
}
 
ll calcComb(ll n,ll r){
    return modMul(fact(n),modMul(invFact(n-r),invFact(r)));
}
 
void realmsDomain(){
  ll n,m; cin>>n>>m;
  vector<ll>st(n+1);
 
  for(ll i=1;i<n+1;i++){
    st[i] = calcComb(m-1+n-i,m-1);
    deb(st[i],i);
  }
 
  ll ans=0;
  for(ll i=1;i<n+1;i++){
    ll p = calcComb(m+i-2,m-1);
    ll s=0;
    for(ll j=i;j<n+1;j++){
        s= modSum(s,st[j]);
    }
    deb(p,s);
    ans = modSum(ans,modMul(p,s));
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
 
    // cin>>tsts;    
 
    for(ll testcase = 1 ; testcase <=  tsts ; testcase++ ){
        realmsDomain();
    }
 
    #ifdef chandan
    cerr << "Time : " << fixed << setprecision(6) << ((double)(clock() - time_req)) / CLOCKS_PER_SEC << endl;
    #endif
 
    return 0;
}