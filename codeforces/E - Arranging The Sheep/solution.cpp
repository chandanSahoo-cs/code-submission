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
  ll n; cin>>n;
  string s; cin>>s;
 
  ll stars = 0;
  for(auto c:s){
    stars+=c=='*';
  }
 
  if(!stars){
    cout<<"0\n";
    return;
  }
 
  vector<pair<ll,ll>>pref(n);  
  vector<pair<ll,ll>>suff(n);
 
  ll cnt = 0;
  for(ll i=0;i<n;i++){
    ll sum = i>0?pref[i-1].first:0;
    sum+=cnt;
    if(s[i]=='*') cnt++;
    pref[i] = {sum,cnt};
  }    
 
 
  cnt = 0;
  for(ll i=n-1;i>=0;i--){
    ll sum = i<n-1?suff[i+1].first:0;
    sum+=cnt;
    if(s[i]=='*') cnt++;
    suff[i] = {sum,cnt};
  }    
 
  deb(pref);
  deb(suff);
 
  ll mn = LLONG_MAX;
 
  auto compute = [&](pair<ll,ll>&p)->ll{
    ll val = p.first;
    ll m = p.second;
 
    ll sub = (m*(m-1))/2;
 
    return val-sub;
  };
 
  for(ll i=0;i<n;i++){
    if(s[i]!='*') continue;
    ll left = i==0?0:compute(pref[i-1]);
    ll right = i==n-1?0:compute(suff[i+1]);
 
    mn = min(mn,left+right);
  }
 
  cout<<mn<<"\n";  
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