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
  vector<ll>odd(n);
  ll o=0;
  for(ll i=0;i<n;i++){
    if(a[i]%2) o++;
    odd[i]=o;
  }
  deb(odd);
  while(q--){
    ll l,r,k; cin>>l>>r>>k;
    l--,r--;
    ll currOdd=odd[n-1]-odd[r]+(l!=0?odd[l-1]:0);
    deb(currOdd);
    if(k%2){
      currOdd+=r-l+1;
    }
    if(currOdd%2){
      cout<<"YES"<<"\n";
    }
    else cout<<"NO"<<"\n";
  }
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