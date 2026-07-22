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
 
ll calc(ll prev, ll next){
  return next-prev-2;
}
 
void realmsDomain(){
    ll n,q,k; cin>>n>>q>>k;
 
    vector<ll>a(n);
    for(auto &ele:a) cin>>ele;
 
    vector<ll>pref(n+1);
 
    for(ll i=0;i<n;i++){
      ll prev = i==0?0:a[i-1];
      ll next = i==n-1?k+1:a[i+1];
 
      pref[i+1] = next-prev-2;
    }
 
    deb(pref);
 
    for(ll i=1;i<=n;i++){
      pref[i]+=pref[i-1];
    }
 
    while(q--){
      ll l,r; cin>>l>>r;
 
      if(l==r){
        cout<<k-1<<"\n";
      }else{
        ll left = pref[l];
        ll right = pref[r-1];
        deb(left,right);
        cout<<right-left+(calc(0,l==n?k+1:a[l])+calc(r==1?0:a[r-2],k+1))<<"\n";
      }
    }
 
    return;
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