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
 
ll compute(string &a, string &b, ll strt){
  ll n = a.size();
  vector<ll>zero,one;
 
  ll jumps = 0;
  for(ll i=strt;i<n;i+=2){
    if(a[i]=='1') one.push_back(jumps);
    else zero.push_back(jumps);
    jumps++;
  }
 
  ll szZ = zero.size();
  ll szO = one.size();
 
  ll j = 0, k = 0;
  ll cnt = 0;
  jumps=0;
 
  for(ll i=strt;i<n;i+=2){
    if(b[i]=='0'){
      if(j>=szZ) return -1;
      cnt+=abs(jumps-zero[j]);
      j++;
    }
    jumps++;
  }
 
  if(j<szZ) return -1;
 
  return cnt;
}
 
void realmsDomain(){
  ll n; cin>>n;
  string a,b; cin>>a>>b;
 
  ll even = compute(a,b,0);
  ll odd = compute(a,b,1);
 
  if(odd==-1 || even==-1){
    cout<<"-1\n";
  }else cout<<even+odd<<"\n";
 
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