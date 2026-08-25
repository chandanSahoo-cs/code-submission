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
 
/*
get all the values that appear more than once
get bits of all the elements
 
for all the values that appear more than once
check if their set bits are turned off in any
other number , if yes it can't be used
 
if not
get the factorial of that of it's occurrences
*/
 
void realmsDomain(){
  ll n; cin>>n;
  vector<ll>a(n);
  vector<ll>bits(30);
  map<ll,ll>mp;
 
  for(auto &ele:a){
    cin>>ele;
    for(ll mask=0;mask<30;mask++){
      if(ele&(1<<mask)) bits[mask]++;
    }
    mp[ele]++;
  }
 
  deb(bits);
 
  ll cnt = 0;
 
  ll mid = 1;
 
  for(ll i=1;i<=n-2;i++){
    mid = (mid*i)%mod;
  }
  deb(mid);
 
  for(auto &[key,value]:mp){
    if(value<2) continue;
 
    bool flag = true;
    for(ll mask=0;mask<30;mask++){
      if(key&(1<<mask) && bits[mask]!=n){
        flag = false;
        break;
      }
    }
 
    deb(flag);
 
    if(flag){
      ll temp = (value*(value-1))%mod;
 
      temp = (temp*mid)%mod;
      cnt = (cnt+temp)%mod;
      break;
    }
  }
 
  cout<<cnt<<"\n";
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