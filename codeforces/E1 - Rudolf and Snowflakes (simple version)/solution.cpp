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
 
const int len = 1e6+1;
 
vector<bool>mark(len,false);
 
void markinmark(ll k){
  ll c = 1 + k;
  ll strt=k;
  for(int i=2;i<=20;i++){
    strt*=k;
    c+=strt;
    if(c>1e6) break;
    mark[c]=true;
  }
}
 
 
void foo(){
  for(ll i=2;i<=1e6;i++){
    markinmark(i);
  }
}
 
 
void realmsDomain(){
  ll n; cin>>n;
  if(mark[n]) cout<<"YES\n";
  else cout<<"NO\n";
}
 
int main() {
    clock_t time_req = clock();
    velociraptor
 
 
    #ifdef chandan 
    freopen("error.txt", "w", stderr); 
    #endif
 
    ll tsts = 1 ; 
    cin>>tsts;   
 
    foo();
 
    for(ll testcase = 1 ; testcase <=  tsts ; testcase++ ){
        realmsDomain();
    }
 
    #ifdef chandan
    cerr << "Time : " << fixed << setprecision(6) << ((double)(clock() - time_req)) / CLOCKS_PER_SEC << endl;
    #endif
 
    return 0;
}