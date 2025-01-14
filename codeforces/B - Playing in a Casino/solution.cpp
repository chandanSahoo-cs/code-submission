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
  ll n,m; cin>>n>>m;
  vector<vector<ll>>a(m,vector<ll>(n));
  for(ll i=0;i<n;i++){
    for(ll j=0;j<m;j++){
      cin>>a[j][i];
    }
  }
 
  if(n==1){
    cout<<"0\n";
    return;
  }
 
  vector<ll>sum;
  for(auto &ele:a){
    sort(all(ele));
    sum.push_back(accumulate(all(ele),0LL));
  }
  ll ans=0;
 
  for(ll i=0;i<m;i++){
    ll curr = 0;
    for(ll j=0;j<n;j++){
      curr+=a[i][j];
      ans+=abs(sum[i]-curr-(n-1-j)*a[i][j]);
    }
  }
 
  cout<<ans<<"\n";
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