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
  ll n,s; cin>>n>>s;
  vector<ll>a(n);
 
  ll sum = 0;
  for(auto &ele:a) cin>>ele, sum+=ele;
 
  if(sum==s){
    cout<<"0\n";
    return;
  }
  if(sum<s){
    cout<<"-1\n";
    return;
  }
 
  ll l = 0, r = 0;
  ll ans = INT_MAX;
  sum=0;
 
  while(r<n){
    sum+=a[r];
 
    while(l<=r && sum>s){
      sum-=a[l];
      l++;
    }
 
    if(sum==s) ans = min(ans,n-(r-l+1));
    r++;
  }
  
  cout<<ans<<"\n";
 
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