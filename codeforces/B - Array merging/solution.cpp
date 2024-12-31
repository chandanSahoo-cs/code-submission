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
  vector<ll>a(n);  
  vector<ll>b(n);
  map<ll,ll>mpa,mpb;
  ll mx = -1;
  for(auto &ele:a) cin>>ele,mx = max(mx,ele),mpa[ele]=0;
  for(auto &ele:b) cin>>ele,mx = max(mx,ele),mpb[ele]=0;
 
 
  ll mxFreq = 1;
  ll e = a[0];
 
  for(ll i=1;i<n;i++){
    if(a[i]!=e){
      mpa[e] = max(mxFreq,mpa[e]);
      e=a[i];
      mxFreq = 1;
    }
    else{
      mxFreq++;
    }
  }
  mpa[e]=max(mpa[e],mxFreq);
  deb(mpa);
 
  mxFreq = 1;
  e = b[0];
 
  for(ll i=1;i<n;i++){
    if(b[i]!=e){
      mpb[e] = max(mxFreq,mpb[e]);
      e = b[i];
      mxFreq = 1;
    }
    else{
      mxFreq++;
    }
  }
  mpb[e]=max(mpb[e],mxFreq);
  deb(mpb);
 
  ll ans = 1;
  for(ll i=1;i<=mx;i++){
    ll at = 0;
    if(mpa.find(i)!=mpa.end()) at+=mpa[i];
    if(mpb.find(i)!=mpb.end()) at+=mpb[i];
    ans=max(ans,at);
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