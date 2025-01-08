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
  string s; cin>>s;
  ll mx=0;
  ll cnt=0;
  s+=s;
  for(ll i=0;i<(ll)s.size();i++){
    if(s[i]=='1'){
      cnt++;
      mx = max(mx,cnt);
    }
    else{
      cnt=0;
    }
  }
  if(mx==(ll)s.size()){
    cout<<mx/2*mx/2<<"\n";
    return;
  }
  ll ans=0;
 
  for( ll i=1;i<=mx;i++){
    ans = max(ans, (mx-i+1)*i);
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