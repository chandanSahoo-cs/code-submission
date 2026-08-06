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
  set<ll,greater<>>st;
  vector<ll>freq(1001);
 
  for(ll i=0;i<n;i++){
    ll ele; cin>>ele;
    st.insert(ele);
    freq[ele]++;
  }
 
  vector<ll>a(all(st));
  ll sum = 0;
  bool flag=true;
  ll m = a.size();
 
  for(ll i=0;i<m;i++){
    sum+=min(n-freq[a[i]]+1,freq[a[i]])*a[i];
 
    if(n-freq[a[i]]+1<freq[a[i]] && flag){
      sum+=a[i];
      flag = false;
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