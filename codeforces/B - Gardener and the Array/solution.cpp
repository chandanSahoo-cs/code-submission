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
  bool ans=false;
  map<ll,ll>a;
 
  vector<vector<ll>>p;
 
  for(ll i=0;i<n;i++){
    ll k; cin>>k;
    vector<ll>temp;
    for(ll i=0;i<k;i++){
        ll ele; cin>>ele;
        temp.push_back(ele);
        a[ele]++;
    }
    p.push_back(temp);
  }
 
  for(ll i=0;i<n;i++){
    bool cmp=true;
    for(ll j=0;j<(ll)p[i].size();j++){
        if(a[p[i][j]]<2) cmp=false;
    }
    if(cmp){
        ans=true;
        break;
    }
  }
 
  if(ans){
    cout<<"YES\n";
  }else cout<<"NO\n";  
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