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
  ll a,b,x; cin>>a>>b>>x;
  ll ans = LLONG_MAX;
 
  ll diva = 0;    
 
  for(ll i=a;i>=0;i/=x){
    ll divb = 0;
    for(ll j=b;j>=0;j/=x){
 
        if(i==j){
            ans = min(ans,diva+divb);
            break;
        }else{
            ll mx = max(i,j), mn = min(i,j);
            ans = min(ans,diva+divb+mx-mn);
        }
 
        divb++;
        if(j==0) break;
    }
 
    diva++;
    if(i==0) break;
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