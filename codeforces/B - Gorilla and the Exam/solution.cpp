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
  map<ll,ll>mp;
  for(ll i=0;i<n;i++){
    ll ele; cin>>ele;
    mp[ele]++;
  }
  vector<ll>b;
 
  for(auto ele:mp) b.push_back(ele.second);
  sort(all(b),greater());  
  ll i=b.size()-1;      
  while(k && i>0){
    if(b[i]<=k){
        k-=b[i];
        b.pop_back();
    }
    else if(b[i]>k) break;
    i--;
  }
  cout<<b.size()<<"\n";  
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