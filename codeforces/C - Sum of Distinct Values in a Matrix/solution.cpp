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
 
void realmsDomain(){
  ll n,m,x,y; cin>>n>>m>>x>>y;
  vector<ll>a(x),b(y);
 
  vector<ll>freq(n+m+1);
 
  for(auto &ele:a) cin>>ele, freq[ele]++;  
  for(auto &ele:b) cin>>ele, freq[ele]++;
 
  vector<ll>store;
    
  for(ll i=0;i<=n+m;i++){
    if(freq[i]==2) store.push_back(i);
  }
 
  ll cntn = 0, cntm = 0;
 
  for(ll i=x-1;i>=0;i--){
    if(freq[a[i]]!=2 && cntn<n) store.push_back(a[i]), cntn++;
  }
 
  for(ll i=y-1;i>=0;i--){
    if(freq[b[i]]!=2 && cntm<m) store.push_back(b[i]), cntm++;
  }
 
 
  sort(all(store),greater());
 
  ll sum=0;
  for(ll i=0;i<min((ll)store.size(),n+m-1);i++){
    sum+=store[i];
  }  
 
  cout<<sum<<"\n";  
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