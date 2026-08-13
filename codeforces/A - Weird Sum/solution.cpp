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
  vector<vector<ll>>x(100001),y(100001);
 
  for(ll i=1;i<=n;i++){
    for(ll j=1;j<=m;j++){
      ll ele; cin>>ele;
      x[ele].push_back(i);
      y[ele].push_back(j);
    }
  }
 
  ll sumx = 0, sumy = 0;
 
  for(ll i=1;i<=1e5;i++){
    ll sz = x[i].size();
    if(sz==0) continue;
    sort(all(x[i]),greater());
 
    ll sum = accumulate(all(x[i]),0LL);
 
    for(ll j=0;j<sz;j++){
      sumx+=(x[i][j]*(sz-j))-sum;
      sum-=x[i][j];
    }
 
    deb(i,sumx);
  }   
 
  for(ll i=1;i<=1e5;i++){
    ll sz = y[i].size();
    sort(all(y[i]),greater());
 
    ll sum = accumulate(all(y[i]),0LL);
 
    for(ll j=0;j<sz;j++){
      sumy+=(y[i][j]*(sz-j))-sum;
      sum-=y[i][j];
    }
  }
 
  cout<<sumx+sumy<<"\n"; 
}
 
int main() {
    clock_t time_req = clock();
    velociraptor
 
 
    #ifdef chandan 
    freopen("error.txt", "w", stderr); 
    #endif
 
    ll tsts = 1 ; 
 
    // cin>>tsts;    
 
    for(ll testcase = 1 ; testcase <=  tsts ; testcase++ ){
        realmsDomain();
    }
 
    #ifdef chandan
    cerr << "Time : " << fixed << setprecision(6) << ((double)(clock() - time_req)) / CLOCKS_PER_SEC << endl;
    #endif
 
    return 0;
}