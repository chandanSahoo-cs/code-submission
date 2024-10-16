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
  for(auto &ele:a)cin>>ele;
 
  vector<pair<ll,ll>>colors(n+1);
 
  for(ll i=0;i<n;i++){
    if(colors[a[i]].first==0){
        colors[a[i]].first=i+1;
        colors[a[i]].second++;
    }
    else{
        if((colors[a[i]].first+i+1)%2!=0){
            deb(colors[a[i]],i,a[i]);
            colors[a[i]].first=i+1;
            colors[a[i]].second++;
        }
    }
    // deb(colors);
  }
 
  for(ll i=1;i<=n;i++){
    cout<<colors[i].second<<" ";
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