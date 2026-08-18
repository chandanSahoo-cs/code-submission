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
  ll n,m; cin>>n>>m;
  vector<ll>a(n),b(m);
 
  for(auto &ele:a) cin>>ele;
  for(auto &ele:b) cin>>ele;  
    
  ll bea = a[n-1], ver = b[m-1];
 
  for(ll i=0;i<n-1;i++){
    bea+=(a[i]-a[i+1]+1);
  }
 
  for(ll i=0;i<m-1;i++){
    ver+=(b[i]-b[i+1]+1);
  }
 
  if(bea>=ver) cout<<"1\n";
  else cout<<"2\n";
 
  return;
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