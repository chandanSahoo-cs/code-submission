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
 
ll pos(vector<ll>&a, ll idx){
  ll n = a.size();
  ll cnt = 0;
  ll prev = 0;
 
  for(ll i=idx+1;i<n;i++){
    ll req = (prev+a[i]-1)/a[i];
    if(a[i]*req==prev) req++;
    cnt+=req;
    prev = req*a[i];
  }
 
  return cnt;
}
 
ll neg(vector<ll>&a, ll idx){
  ll n = a.size();
  ll cnt = 1;
  ll prev = a[idx];
 
  for(ll i=idx-1;i>=0;i--){
    ll req = (prev+a[i]-1)/a[i];
    if(a[i]*req==prev) req++;
    cnt+=req;
    prev = req*a[i];
  }
 
  return cnt;
}
 
void realmsDomain(){
  ll n; cin>>n;
  vector<ll>a(n);
  for(auto &ele:a) cin>>ele;
  ll mn = LLONG_MAX;
 
  for(ll i=0;i<n;i++){
    ll cnt = pos(a,i);
    if(i>0){
      cnt+=neg(a,i-1);
    }
 
    mn = min(mn,cnt);
  }
 
  cout<<mn<<"\n";  
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