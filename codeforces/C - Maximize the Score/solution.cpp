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
 
ll dp[400005];
 
ll rec(vector<ll>&a, vector<ll>&idx, ll i){
  ll n = a.size();
  if(i>=n) return 0;
 
  if(dp[i]!=-1) return dp[i];
 
  ll mx = 1+rec(a,idx,i+1);
 
  if(idx[a[i]]!=i){
    ll val = idx[a[i]]-i+1;
    mx = max(mx,val*val+rec(a,idx,idx[a[i]]+1));
  }
 
  return dp[i] = mx;
}
 
void realmsDomain(){
  ll n; cin>>n;
  vector<ll>a(2*n);
 
  /*this array will store right idx for each ele*/
  vector<ll>idx(n+1);
  for(auto &ele:a) cin>>ele;
 
  for(ll i=0;i<2*n;i++){
    idx[a[i]]=i;
  }
 
  for(ll i=0;i<=2*n;i++){
    dp[i]=-1;
  }
 
  cout<<rec(a,idx,0)<<"\n";
 
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