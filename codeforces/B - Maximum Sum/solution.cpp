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
    vector<ll>a(n);
    for(auto &ele:a) cin>>ele;
    sort(all(a));  
    vector<ll>suff=a,pref=a;
    deb(a);
    for(ll i=1;i<n;i++){
      pref[i]+=pref[i-1];
    }
 
    for(ll i=n-2;i>=0;i--){
      suff[i]+=suff[i+1];
    }  
 
    deb(pref);
    deb(suff);
 
    ll l=2*k-1;
    ll r=n;
 
    ll ans = -1;
 
    while(r>=n-k){
      ll left=0,right=0;
      if(l>0) left = pref[l];
      if(r<n) right = suff[r];
      ans = max(ans,pref.back()-left-right);
      l-=2;
      r--;
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