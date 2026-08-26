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
ci+1 - ci = bci+1 - bci
bci-ci = bci+1-ci+1;
 
10 7 1 9 10 15
1  2 3 4  5  6
9  5 -2 5 5 
*/
 
void realmsDomain(){
  ll n; cin>>n;
 
  map<ll,ll>mp;
  ll mx = 0;
 
  for(ll i=1;i<=n;i++){
    ll ele; cin>>ele;
    mp[ele-i]+=ele;
 
    mx = max(mx,mp[ele-i]);
  }
 
  cout<<mx<<"\n";
}
 
int main() {
    clock_t time_req = clock();
    velociraptor
 
 
    #ifdef chandan 
    freopen("error.txt", "w", stderr); 
    #endif
 
    ll tsts = 1 ; 
 
    // cin>>tsts;    
 
    for(ll testcase = 1 ; testcase <=  tsts ; testcase++ ){
        realmsDomain();
    }
 
    #ifdef chandan
    cerr << "Time : " << fixed << setprecision(6) << ((double)(clock() - time_req)) / CLOCKS_PER_SEC << endl;
    #endif
 
    return 0;
}