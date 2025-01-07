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
  ll n,q; cin>>n>>q;
  vector<ll>a(n);
  for(auto &ele:a) cin>>ele;
  vector<ll>mark(31,0);
  vector<ll>Pow(31);
 
  for(ll i=0;i<31;i++){
    Pow[i]=1<<i;
  }
  ll mx=-1;
  for(ll i=0;i<q;i++){
    ll x; cin>>x;
    if(!mark[x] && (x<mx || i==0)){
      for(auto &ele:a){
        if(ele%Pow[x]==0) ele+=Pow[x-1];
      }
      mark[x]=1;
      mx = max(mx,x);
    }
  }
 
  for(auto &ele:a) cout<<ele<<" ";
  cout<<"\n";  
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