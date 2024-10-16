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
  string s; cin>>s;
  vector<ll>a(n);
  for(auto &ele:a) cin>>ele;
  multiset<ll>mst;
  ll cnt=0;
  bool flag=false;
 
  for(ll i=0;i<n;i++){
    if(s[i]=='1'){
        mst.insert(a[i]);
        if(i-1>=0 && s[i-1]=='0') mst.insert(a[i-1]), flag=true;
        deb(mst);
    }
    else if(s[i]=='0' && i!=0 && s[i-1]=='1'){
        if(flag) mst.extract(*mst.begin());
        deb(mst);
        for(auto ele:mst) cnt+=ele;
        mst.clear();
        deb(mst);
        flag=false;
    }
    deb(cnt);
  }
 
  if(!mst.empty()){
    if(flag) mst.extract(*mst.begin());
    for(auto ele:mst) cnt+=ele;
  }
 
  cout<<cnt<<"\n";
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