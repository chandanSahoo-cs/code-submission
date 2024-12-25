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
  ll x,y,z; cin>>x>>y>>z;
  ll a;
  // for x
  a=y+z-3*(z-y);
  deb(a);
  if(a>0 && a%2==0 && (a/2)%x==0){
    cout<<"YES"<<"\n";
    deb(1);
    return;
  }
 
  // for y 
  a=x+z;
  if(a>0 && a%2==0 && (a/2)%y==0){
    cout<<"YES"<<"\n";
    deb(2);
    return;
  }
 
  //for z
 
  a=x+y+3*(y-x);
  if(a>0 && a%2==0 && (a/2)%z==0){
    cout<<"YES"<<"\n";
    deb(3);
  }
  else cout<<"NO"<<"\n";
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