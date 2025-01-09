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
  ll n,k; cin>>n>>k;
  vector<vector<ll>>a(n,vector<ll>(n));
  for(ll i=0;i<n;i++){
    for(ll j=0;j<n;j++){
      cin>>a[i][j];
    }
  }
 
  for(ll i=0;i<(n+1)/2;i++){
    for(ll j=0;j<n;j++){
      if(a[i][j]!=a[n-1-i][n-1-j]){
        k--;
        a[i][j]=a[n-1-i][n-1-j];
      }
    }
    if(k<0) break;
  }
  if(k==0) cout<<"YES\n";
  else if(k<0) cout<<"NO\n";
  else {
    if((k&1)==1 && (n&1)==0) cout<<"NO\n";
    else cout<<"YES\n";
  }
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