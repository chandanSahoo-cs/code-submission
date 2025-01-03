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
  ll w,h; cin>>w>>h;
  ll a=-1;
  for(ll i=0;i<4;i++){
    ll n; cin>>n;
    ll mn=LLONG_MAX,mx=-1;
 
    for(ll i=0;i<n;i++){
      ll ele; cin>>ele;
      mn=min(mn,ele);
      mx=max(mx,ele);
    }
 
    if(i<2){
      a=max(a,(mx-mn)*h);
    }
    else{
      a=max(a,(mx-mn)*w);
    }
  }
 
  cout<<a<<"\n"; 
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