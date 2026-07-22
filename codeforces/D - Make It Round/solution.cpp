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
 
  ll cnt2 = 0, cnt5 = 0;
 
  ll t = n;
 
  while(t%2==0){
    cnt2++;
    t/=2;
  }
 
  while(t%5==0){
    cnt5++;
    t/=5;
  }
 
   ll k = 1;
 
   ll val = (cnt2<cnt5)?2:5;
 
   while(k*val<=m && cnt2!=cnt5){
    k*=val;
    if(val==2) cnt2++;
    else cnt5++;
   }
 
   while(k*10<=m){
    k*=10;
   }
 
   // deb(k);
 
   for(int i=9;i>=1;i--){
     if(k*i<=m){
      k*=i;
      break;
     }
   }
 
 
   cout<<n*k<<"\n"; 
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