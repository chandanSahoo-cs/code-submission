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
 
ll dp[100005][2];
 
ll rec(vector<ll>&a, vector<ll>&b, ll i, ll p){
  ll n = a.size();
 
  if(i==n) return 0;
 
  if(dp[i][p]!=-1) return dp[i][p];
 
  ll mx = 0;
  
  // pick
  mx = max(mx,(p?a[i]:b[i])+rec(a,b,i+1,!p));
 
  // not pick
  mx = max(mx,rec(a,b,i+1,p));
 
  return dp[i][p] = mx;
}
 
void realmsDomain(){
  ll n; cin>>n;
 
  vector<ll>a(n),b(n);
 
  for(auto &ele:a) cin>>ele;  
  for(auto &ele:b) cin>>ele;
 
  for(ll i=0;i<=n;i++){
    dp[i][0] = dp[i][1] = -1;
  }
 
  cout<<max(rec(a,b,0,0),rec(a,b,0,1))<<"\n";
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