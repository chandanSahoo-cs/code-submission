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
/*
phele sort kiya
uske baad prefix sum arraya banaya
uske baad check kiya ki jo mere a[i]th woh apne agle wale se bada hai ya nhi agar hai toh aage bado and continue
the same step nhi toh break aur starting se leke end tk woh cnt bhar do uske baad next index pe same jb tk last tk nhi
pahunch jaate
*/
void realmsDomain(){
  ll n; cin>>n;
  vector<ll>a(n);
  vector<pair<ll,ll>>b;
 
  for(ll i=0;i<n;i++){
    cin>>a[i];
    b.push_back({a[i],i});
  }
  sort(all(b));
 
  sort(all(a));
  for(ll i=1;i<n;i++){
    a[i]=(a[i]+a[i-1]);
  }
 
  vector<pair<ll,ll>>ans(n);
 
 
  ll i=0;
  while(i<n-1){
    ll l=i;
    ll r=i;
    ll cnt=i;
    while(a[r]>=(b[r+1].first) && r<n-1){
      r++;
      cnt++;
    }
    while(l<=r){
      ans[l]={cnt,b[l].second};
      l++;
    }
    i=r+1;
  }
  ans[n-1]={n-1,b[n-1].second};
 
  sort(all(ans),[&](pair<ll,ll>p1, pair<ll,ll>p2){
    return p1.second<p2.second;
  });
 
  for(auto ele:ans){
    cout<<ele.first<<" ";
  }
 
  cout<<"\n";
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