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
  vector<ll>a(n),b(m);
 
  for(auto &ele:a) cin>>ele;
  for(auto &ele:b) cin>>ele;
 
  if(n<2*m){
    cout<<"NO\n";
    return;
  }
 
  sort(all(a));
  sort(all(b));
 
  ll j = 0;
 
  for(ll i=0;i<n;i++){
    if(j==m) break;
    if(a[i]>b[j]){
      cout<<"NO\n";
      return;
    }
    a[i]=-1;
    j++;
  }
 
  j = m-1;
 
  for(ll i=n-1;i>=0;i--){
    if(j==-1) break;
    if(a[i]<b[j]){
      cout<<"NO\n";
      return;
    }
    j--;
  }
  
  cout<<"YES\n";
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