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
  ll n; cin>>n;
  vector<ll>a(n),b(n);
 
  for(auto &ele:a) cin>>ele;
  for(auto &ele:b) cin>>ele;
 
  sort(all(a),greater());
  sort(all(b),greater());
 
  ll cnt = 0;
  ll extra = 0;
 
  for(ll i=0;i<n;i++){
    if(a[i]+extra<b[i]){
        cout<<"-1\n";
        return;
    }else{
        cnt+=max(0LL,a[i]-b[i]);
        extra += a[i]-b[i];
    }
  }
 
  if(extra>0) cout<<"-1\n";
  else cout<<cnt<<"\n"; 
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