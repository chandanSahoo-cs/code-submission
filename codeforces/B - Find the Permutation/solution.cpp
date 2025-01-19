/*It is not the matter of if, it is the matter of when*/
        
#include "bits/stdc++.h"
using namespace std;
 
#define velociraptor ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);                                             
#define all(v) v.begin(),v.end()
#define lcd(a,b) (a*b)/__gcd(a,b)
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
  for(ll i=0;i<n;i++){
    string s; cin>>s;
    ll cnt=0;
    for(ll j=0;j<n;j++){
      if((s[j]=='0' && i<j) || (s[j]=='1' && i>j)) cnt++;
      deb(i,j);
    }
    deb(i,cnt);
    a[i]=cnt;
  }
  deb(a);
  vector<ll>foo(n);
  iota(all(foo),0);
 
  sort(all(foo),[&](ll i,ll j){
    return a[i]<a[j];
  });
 
  for(auto ele:foo) cout<<ele+1<<" ";
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