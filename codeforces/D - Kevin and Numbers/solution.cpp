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
 
bool fndMe(multiset<ll>&a,ll ele){
  deb(a);
  deb(ele);
 
  if(ele==0 || a.size()==0) return false;
  if(a.find(ele)!=a.end()){
    a.extract(ele);
    return true;
  }
 
  bool flag1=false,flag2=false;
  auto it = a.find(ele/2);
  if(it!=a.end()){
    a.extract(ele/2);
    flag1=true;
  }
  else{
    flag1 = fndMe(a,ele/2);
  }
 
  auto it2 = a.find(ele-ele/2);
  if(flag1){
    if(it2!=a.end()){
      a.extract(ele-ele/2);
      flag2=true;
    }
    else{
      flag2 = fndMe(a,ele-ele/2);
    }
  }
  if(flag1 && flag2){
    return true;
  }
  else{
    return false;
 
  }
}
 
void realmsDomain(){
  ll n,m; cin>>n>>m;
  multiset<ll>a,b;
 
  for(ll i=0;i<n;i++){
    ll ele; cin>>ele;
    a.insert(ele);
  }
 
 
  for(ll j=0;j<m;j++){
    ll ele; cin>>ele;
    b.insert(ele);
  }
  // deb(a);
  // deb(b);
  for(auto &ele:b){
    bool  flag= fndMe(a,ele);
    deb(flag);
    if(!flag){
      cout<<"NO\n";
      return;
    }
  }
 
  if(a.size()!=0){
    cout<<"NO\n";
    return;
  }
 
  cout<<"YES\n";
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