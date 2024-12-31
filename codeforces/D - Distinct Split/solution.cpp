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
  string s; cin>>s;
 
  vector<ll>alphaFor(26,0);
  vector<ll>alphaBac(26,0);
 
  vector<ll>a(n);
  vector<ll>b(n);
 
  for(ll i=0;i<n;i++){
    if(alphaFor[s[i]-'a']==0){
      a[i]++;
      alphaFor[s[i]-'a']=1;
    }
    if(i!=0){
      a[i]+=a[i-1];
    }
  }
 
  deb(a);
 
  for(ll i=n-1;i>=0;i--){
    if(alphaBac[s[i]-'a']==0){
      b[i]++;
      alphaBac[s[i]-'a']=1;
    }
    if(i!=n-1){
      b[i]+=b[i+1];
    }
  }
 
  deb(b);
 
  ll ans=-1;
 
  for(ll i=0;i<n-1;i++){
    ans=max(ans,a[i]+b[i+1]);
  }
 
  ans=max(ans,a[n-1]);
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