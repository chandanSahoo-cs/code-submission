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
  vector<vector<int>>adj(n+1);
 
  for(int i=0;i<m;i++){
    ll a,b; cin>>a>>b;
    if(a>b) swap(a,b);
 
    adj[b].push_back(a);
  }
 
  ll l = 1, r = 1;
  ll cnt = 0;
 
  while(r<=n){
 
    int i = 0;
    while(i<adj[r].size() && adj[r][i]<l) i++; 
 
    while(i<adj[r].size()){
        l++;
        while(i<adj[r].size() && adj[r][i]<l) i++; 
    }
 
    cnt+=r-l+1; 
    r++;
  }
 
  cout<<cnt<<"\n";
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