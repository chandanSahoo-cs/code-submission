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
  vector<vector<ll>>a(n,vector<ll>(n));
  for(ll i=0;i<n;i++){
    for(ll j=0;j<n;j++){
        cin>>a[i][j];
    }
  }
  ll cnt=0;
  map<ll,ll>mp;
  for(ll i=0;i<n;i++){
    for(ll j=0;j<n;j++){
        if(a[i][j]<0){
            deb(mp);
            if(mp.find(i-j)==mp.end()){
                mp[i-j]=a[i][j];
            }
            mp[i-j]=min(mp[i-j],a[i][j]);
        }
    }
  }
  for(auto ele:mp){
    cnt+=ele.second;
  }
  cout<<abs(cnt)<<"\n";
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