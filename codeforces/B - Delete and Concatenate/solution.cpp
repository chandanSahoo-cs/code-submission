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
  ll n,c; cin>>n>>c;
  vector<ll>a(n);
 
  for(auto &ele:a) cin>>ele;
 
  vector<ll>b;
  ll sum = 0;
 
  for(ll i=0;i<n;i++){
    ll temp = a[i]-c;
 
    if(temp>0){
      sum+=temp;
    }else{
      b.push_back(temp);
    }
  }
 
  deb(sum);
 
  sort(all(b),greater());
  deb(b);
 
  ll negCnt = b.size();
  ll posCnt = n-negCnt;
 
  ll k = negCnt-posCnt;
 
  if(k>0){
    for(ll i=0;i<(k+1)/2;i++){
      sum+=b[i];
    }
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