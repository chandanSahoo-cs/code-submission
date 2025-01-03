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
  vector<ll>a(n);
 
  for(auto &ele:a) cin>>ele;
 
  vector<ll>foo(n,0);
  iota(all(foo),0);
 
  sort(all(foo),[&](ll i,ll j){
    return a[i]>a[j];
  });
  deb(foo);
  map<ll,ll>mp;
  ll k=1;
  ll sum=0;
  for(auto ele:foo){
    if(k>0) mp[ele]=k,k=-k;
    else mp[ele]=k,k=abs(k)+1;
    sum+=a[ele]*2*abs(0-mp[ele]);
  }
  deb(mp);
  cout<<sum<<"\n";
  cout<<0<<" ";
 
  for(ll i=0;i<n;i++){
    cout<<mp[i]<<" ";
  }
 
  cout<<"\n";
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