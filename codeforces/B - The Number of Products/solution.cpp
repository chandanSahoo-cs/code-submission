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
 
/*
5 -3 3 -1 1
0 1 0 1 0
 
 
*/
 
void realmsDomain(){
  ll n; cin>>n;
  vector<ll>a(n);
 
  for(auto &ele:a) cin>>ele;
 
  vector<ll>pref(n);
  pref[0] = (a[0]<0);
 
  ll odd = pref[0];
 
  for(ll i=1;i<n;i++){
    pref[i]=pref[i-1]+(a[i]<0);
 
    odd+=(pref[i]&1);
  }
 
  ll even = n-odd;
 
  deb(pref);
 
  ll change = 0;
 
  ll total = (n*(n+1))/2;
  ll cntOdd = 0;
 
  for(ll i=0;i<n;i++){
    if(change&1){
      cntOdd+=even;
    }else{
      cntOdd+=odd;
    }
 
    if(pref[i]&1) odd--;
    else even--;
 
    if(a[i]<0) change++;
  }
 
  cout<<cntOdd<<" "<<total-cntOdd<<"\n";  
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