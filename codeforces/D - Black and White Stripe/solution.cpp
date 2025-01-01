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
  ll n,k; cin>>n>>k;
  string s; cin>>s;
  string cmp = "";
  vector<ll>whiteCnt(n);
  ll w=0;
  for(ll i=0;i<n;i++){
    if(s[i]=='W') w++;
    whiteCnt[i]=w;
  }
  deb(whiteCnt);
  ll st=0,e=k-1;
  ll ans=LLONG_MAX;
  while(e<n){
    ll totW = whiteCnt[e]-(st==0?0:whiteCnt[st-1]);
    deb(st,e,totW);
    ans=min(ans,totW);
    st++,e++;
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