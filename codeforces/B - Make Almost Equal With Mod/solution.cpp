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
 
/*
if odd and even  : 2
if odd and !even : 4 (dk why)
if !odd and even : ?
 
4 always starts with some even number
so 4+1 is always odd so the mod will be 1
4+2 is always even (not possible that case)
4+3 is always odd and so the mod will be 3
*/
 
void realmsDomain(){
 
  ll n; cin>>n;
  vector<ll>a(n);
  for(auto &ele:a){
      cin>>ele;
  }
 
  for(ll i=1;i<60;i++){
    set<ll>st;
    for(auto &ele:a){
      st.insert(ele%(1LL<<i));
    }
 
    if(st.size()==2){
      cout<<(1LL<<i)<<"\n";
      return;
    }
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