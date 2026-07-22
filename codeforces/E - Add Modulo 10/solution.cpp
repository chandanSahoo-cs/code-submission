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
 
bool check(vector<ll>&a){
  for(auto ele:a){
    if(ele%5==0) return true;
  }
 
  return false;
}
 
void realmsDomain(){
  ll n; cin>>n; 
  vector<ll>a(n);
  for(auto &ele:a) cin>>ele;
 
  if(check(a)){
    ll val1=-1,val2=-1;
 
    for(auto ele:a){
      if(val1==-1 || val1==ele){
        val1 = ele;
      }else if(val2==-1 || val2==ele){
        val2 = ele;
      }else {
        cout<<"NO\n";
        return;
      }
    }
 
    if(val1==-1 || val2==-1){
      cout<<"YES\n";
      return;
    }
 
    if(val1>val2) swap(val1,val2);
 
    if(val2%10){
      cout<<"NO\n";
      return;
    }
 
    if(val1+5==val2){
      cout<<"YES\n";
    }else cout<<"NO\n";
 
    return;
  }
 
  vector<ll>keep;
 
  for(auto ele:a){
    while(ele%10!=2){
      ele+=ele%10;
    }
    keep.push_back(ele/10);
  }
 
 
  ll unit = *min_element(all(keep));
 
  for(ll i=0;i<n;i++){
    if((keep[i]-unit)%2){
      cout<<"NO\n";
      return;
    }
  }
 
  cout<<"YES\n";
 
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