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
  map<ll,ll>mp;
  for(auto &ele:a) cin>>ele,mp[ele]++;
 
  ll e=-1;
 
  for(auto ele:mp){
    if(ele.second>=2){
      e = max(e,ele.first);
    }
  }
 
  if(e==-1){
    cout<<"-1\n";
    return;
  }
 
  mp[e]-=2;
 
  vector<ll>b;
 
  for(auto ele:mp){
    if(ele.second==1)b.push_back(ele.first);
    else if(ele.second>=2){
      b.push_back(ele.first);
      b.push_back(ele.first);
    }
  }
 
  ll prev = b[0];
 
  for(ll i=1;i<(ll)b.size();i++){
    if(abs(b[i]-prev)/2<e){
      cout<<e<<" "<<e<<" "<<prev<<" "<<b[i]<<"\n";
      return;
    }
    prev = b[i];
  }
 
  cout<<"-1\n"; 
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