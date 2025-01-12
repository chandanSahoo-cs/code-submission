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
  ll n; cin>>n;
  vector<ll>a(n),b(n);
  for(auto &ele:a) cin>>ele;
  for(auto &ele:b) cin>>ele;
 
  ll h=0;
  ll ind;
  for(ll i=0;i<n;i++){
    if(a[i]-b[i]<0){
      if(h==0){
        h=a[i]-b[i];
        ind=i;
      }
      else{
        cout<<"NO\n";
        return;
      }
    }
  }
  if(h==0){
    cout<<"YES\n";
    return;
  }
  for(ll i=0;i<n;i++){
    if(i!=ind){
      if(a[i]+h<b[i]){
        cout<<"NO\n";
        return;
      }
    }
  }
 
  cout<<"YES\n";  
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