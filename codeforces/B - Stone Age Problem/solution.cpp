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
  ll n,q; cin>>n>>q;
 
  vector<ll>a(n);
  for(auto &ele:a) cin>>ele;
  ll sum = accumulate(all(a),0LL);
  
  ll counter=0;
  ll hold=0;
 
  vector<ll>mark(n,0);
 
  for(ll i=0;i<q;i++){
    ll t; cin>>t;
    if(t==1){
      ll j,x; cin>>j>>x;
 
      if(mark[j-1]<counter){
        sum-=hold;
        sum+=x;
        a[j-1]=x;
        mark[j-1]=counter;
      }
      else{
        sum-=a[j-1];
        sum+=x;
        a[j-1]=x;
      }
 
    }
    else{
      ll x;cin>>x;
      hold = x;
      sum=n*x;
      counter++;
    }
    cout<<sum<<"\n";
  }
 
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