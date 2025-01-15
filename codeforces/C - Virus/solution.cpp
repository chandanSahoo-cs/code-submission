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
  ll n,m; cin>>n>>m;
  vector<ll>a(m);
  for(auto &ele:a) cin>>ele;
  sort(all(a));
 
  vector<ll>seg;
 
  for(ll i=1;i<m;i++){
    seg.push_back(a[i]-a[i-1]-1);
  }
  seg.push_back(a[0]+n-a.back()-1);
 
  sort(all(seg),greater<ll>());
  deb(seg);
 
  ll y=0;
  ll safe=0;
  for(ll i=0;i<m;i++){
    ll k = 2*y;
    deb(k);
    if(seg[i]-k>0) y++;
    else break;
    if(seg[i]-2-k>0) y++;
    else{
      if(k+1==seg[i]){
        safe+=1;
      }
      else safe+=seg[i]-k-1;
      deb(safe);
      continue;
    }
    safe+=seg[i]-1-k;
    deb(safe);
  }
  cout<<n-safe<<"\n";  
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