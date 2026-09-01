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
  ll n,q; cin>>n>>q;
  string a,b; cin>>a>>b;
 
  vector<ll>c(n+1), d(n+1);
 
  for(ll i=1;i<=n;i++){
    if(a[i-1]=='1' && b[i-1]=='0') c[i]=1;
    else if(a[i-1]=='0' && b[i-1]=='1') d[i]=1;
 
    c[i]+=c[i-1];
    d[i]+=d[i-1];
  }
 
  deb(c,d);
 
  while(q--){
    ll l,r; cin>>l>>r;
    ll m = r-l+1;
 
    ll p1 = c[r]-c[l-1];
    ll p2 = d[r]-d[l-1];
    ll p3 = m-p1-p2;
 
    if(p3>=abs(p1-p2)) cout<<"YES\n";
    else cout<<"NO\n";
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
 
    cin>>tsts;    
 
    for(ll testcase = 1 ; testcase <=  tsts ; testcase++ ){
        realmsDomain();
    }
 
    #ifdef chandan
    cerr << "Time : " << fixed << setprecision(6) << ((double)(clock() - time_req)) / CLOCKS_PER_SEC << endl;
    #endif
 
    return 0;
}