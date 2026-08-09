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
 
bool search(vector<ll>&freq,ll n,ll m,ll t){
  ll tasks = 0;
 
  for(ll i=1;i<=n;i++){
    ll fast = min(t,freq[i]);
    ll slow = (t-fast)/2;
 
    tasks+=fast+slow;
  }
  
  return tasks>=m;
}
 
void realmsDomain(){
  ll n,m; cin>>n>>m;
  vector<ll>a(m);
  vector<ll>freq(n+1);
 
  for(auto &ele:a) cin>>ele,freq[ele]++;
  ll l=0,r=2*m;
  ll ans = 2*m;
 
  while(l<=r){
    ll mid = l+(r-l)/2;
    if(search(freq,n,m,mid)){
      ans = mid;
      r = mid-1;
    }else{
      l = mid+1;
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