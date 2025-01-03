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
 
vector<ll>xr(3e5+1,0);
 
void fill(){
  iota(all(xr),0);
  for(ll i=1;i<=3e5;i++){
    xr[i]^=xr[i-1];
  }
}
 
void realmsDomain(){
  ll a,b; cin>>a>>b;
  if(xr[a-1]==b){
    cout<<a<<"\n";
  }
  else if((xr[a-1]^b)==a){
    cout<<a+2<<"\n";
  }
  else{
    cout<<a+1<<"\n";
  }
}
 
int main() {
    clock_t time_req = clock();
    velociraptor
 
 
    #ifdef chandan 
    freopen("error.txt", "w", stderr); 
    #endif
 
    ll tsts = 1 ; 
 
    cin>>tsts;    
    fill();
    for(ll testcase = 1 ; testcase <=  tsts ; testcase++ ){
        realmsDomain();
    }
 
    #ifdef chandan
    cerr << "Time : " << fixed << setprecision(6) << ((double)(clock() - time_req)) / CLOCKS_PER_SEC << endl;
    #endif
 
    return 0;
}