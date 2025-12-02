/*It is happening, right here and now*/
        
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
   vector<ll>a(n);
   for(auto &ele:a) cin>>ele;
   deb(a); 
   vector<ll>pref(n+1,0);
 
   for(ll i=1;i<=n;i++){
    pref[i]=a[i-1]+pref[i-1];
   }
 
   deb(pref);
 
   double sum=0;
   double len = n-k+1;
   for(ll i=1;i<=len;i++){
    sum+=pref[i+k-1]-pref[i-1];
    deb(sum);
   }
 
   double ans = sum/len;
 
   cout<<fixed<<setprecision(6)<<ans<<"\n";
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