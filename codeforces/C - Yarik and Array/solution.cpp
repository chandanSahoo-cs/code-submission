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
 
ll maxSub(vector<ll>&a){
  ll mx=LLONG_MIN,curr=0;
 
  for(auto ele:a){
    curr = max(ele,curr+ele);
    mx = max(curr,mx);
  }
  return mx;
}
 
bool check (ll a,ll b){
  return (a%2==0 && b%2!=0) || (a%2!=0 && b%2==0);
}
 
void realmsDomain(){
  ll n; cin>>n;
  vector<ll>a(n);
  for(auto &ele:a) cin>>ele;
 
  ll mx=LLONG_MIN;
 
  vector<ll>t = {a[0]};
  for(ll i=1;i<n;i++){
    if(check(a[i],a[i-1])){
      t.push_back(a[i]);
    }
    else{
      mx = max(mx,maxSub(t));
      t = {a[i]};
    }
  }
  mx = max(mx,maxSub(t));
  cout<<mx<<"\n";
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