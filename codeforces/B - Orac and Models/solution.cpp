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
 
ll dp[100005];
 
ll rec(vector<ll>&a, ll i){
  ll n = a.size();
 
  if(i==n) return 0;
 
  if(dp[i]!=-1) return dp[i];
 
  ll mx = 0;
  for(ll j=i+1;j<=n;j+=i+1){
    if(a[i]<a[j-1]){
      mx = max(mx,rec(a,j-1));
    }
  }
 
  return dp[i] = mx+1;
}
 
void realmsDomain(){
  ll n; cin>>n;
  vector<ll>a(n);
 
  for(auto &ele:a) cin>>ele;
 
  for(ll i=0;i<=n;i++){
    dp[i] = -1;
  }
 
  ll mx = 0;
  for(ll i=0;i<n;i++){
    mx = max(mx,rec(a,i));
  }
 
 cout<<mx<<"\n";  
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