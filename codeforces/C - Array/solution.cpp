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
 
template <typename... Args>
 
ll modMul(Args... args){
    ll ans = 1;
    ((ans = (1LL*ans*args)%mod),...);
    return ans;
}
 
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
 
ll calcFact(ll n){
    ll ans = 1;
    for(ll i=1;i<=n;i++){
        ans = modMul(ans,i);
    }
    return ans;
}
 
ll invFact(ll n){
    return binExpMod(calcFact(n),mod-2)%mod;
}
 
void realmsDomain(){
  ll n; cin>>n;
 
  cout<<modMul(2,calcFact(2*n-1),invFact(n),invFact(n-1))-n<<"\n";
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