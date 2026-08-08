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
 
void realmsDomain(){
  ll n; cin>>n;
  vector<ll>a(n);
  for(auto &ele:a) cin>>ele;
 
  vector<ll>b;
  b.push_back(a[0]);
  ll cnt = 1;
 
  for(ll i=1;i<n;i++){
    if(b.back()==a[i]){
      if(cnt<2){
        b.push_back(a[i]);
        cnt++;
      }
    }else{
      cnt=1;
      b.push_back(a[i]);
    }
  }
  
  ll m = b.size();
 
  ll mx = 0;
  ll ind = -1;
 
  for(ll i=1;i<m;i++){
 
    ll prev = 1;
    for(ll j = max(0LL,i-2);j<min(m,i+1);j++){
      if(j+1<m && b[j]!=b[j+1]) prev++;
    }
 
    swap(b[i],b[i-1]);
    ll curr = 1;
 
    for(ll j = max(0LL,i-2);j<min(m,i+1);j++){
      if(j+1<m && b[j]!=b[j+1]) curr++;
    }
 
    if(curr-prev>mx){
      ind = i;
      mx = curr-prev;
    }
 
    swap(b[i],b[i-1]);
  }
 
  if(ind!=-1) swap(b[ind],b[ind-1]);
 
  ll ans = 1;
 
  for(ll i=0;i<m-1;i++){
    ans+=(b[i]!=b[i+1]);
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