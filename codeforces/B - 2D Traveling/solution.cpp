/*It is not the matter of if, it is the matter of when*/
        
#include "bits/stdc++.h"
using namespace std;

#define velociraptor ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);                                             
#define all(v) v.begin(),v.end()
#define lcd(a,b) a*(b/__gcd(a,b))
#define ll long long

const ll mod = 1e9+7;

#ifdef chandan  
#include "starPlatinum.h"
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif

ll calcDist(pair<ll,ll>a,pair<ll,ll>b){
  return llabs(a.first-b.first)+llabs(a.second-b.second);
}

void realmsDomain(){
  ll n,k,a,b; cin>>n>>k>>a>>b;
  vector<pair<ll,ll>>store(n);
  for(auto &ele:store) cin>>ele.first>>ele.second;

  pair<ll,ll>strt = store[a-1];  
  pair<ll,ll>end = store[b-1];  
  ll mnA = 4*mod;
  ll mnB = 4*mod;
  for(ll i=0;i<k;i++){
    mnA = min(mnA,calcDist(store[i],strt));
    mnB = min(mnB,calcDist(store[i],end));
  }
  cout<<min(mnA+mnB,calcDist(strt,end))<<"\n";
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