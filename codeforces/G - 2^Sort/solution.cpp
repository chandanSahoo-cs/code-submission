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
 
bool check(ll u, ll v){
  ll curr = log2(u);
  ll next = log2(v);
 
  if(curr<=next) return true;
  if(curr-1>next) return false;
 
  return u<2*v;
}
 
void realmsDomain(){
  ll n,k; cin>>n>>k;
  vector<ll>a(n);
 
  for(auto &ele:a) cin>>ele;
 
  ll cnt = 0;
  ll run = 0;
 
  for(ll i=1;i<n;i++){
    if(check(a[i-1],a[i])) run++;
    else run = 0;
 
    if(i-k>=0 && run>=k) cnt++;
  }
 
  cout<<cnt<<"\n";  
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