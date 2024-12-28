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
  ll size = 2*n+1;
  vector<ll>mark(size,0);
  vector<ll>occur(size,0);
 
 
  vector<pair<ll,ll>>a(n);
 
  for(auto &ele:a){
    cin>>ele.first>>ele.second;
    if(ele.first==ele.second){
      mark[ele.first]=1;
      occur[ele.first]++;
    }
  }
 
  for(ll i=1;i<size;i++){
    mark[i]=mark[i]+mark[i-1];
  }
 
  string s ="";
  for(auto ele:a){
    ll present = mark[ele.second]-mark[ele.first-1];
    ll tot = ele.second-ele.first+1;
    if(ele.second==ele.first){
      if(occur[ele.first]==1) s+='1';
      else s+='0';
    }
    else if(present<tot){
      s+='1';
    }
    else s+='0';
  }
 
  cout<<s<<"\n";
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