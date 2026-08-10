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
  ll n,k; cin>>n>>k;
  string s; cin>>s;
  string t = s;
  for(ll i=0;i<2*n;i++){
    if(s[i]=='1' && s[(i+1)%(2*n)]=='0'){
      t[(i+1)%(2*n)] = '1';
      t[i] = '0';
    }
  }
  
  ll odd=0,even=0;
 
  for(ll i=0;i<2*n;i++){
    if(i&1 && t[i]=='1') odd++;
    else if(!(i&1) && t[i]=='1') even++;
  }  
 
  cout<<odd<<" "<<even<<"\n";
 
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