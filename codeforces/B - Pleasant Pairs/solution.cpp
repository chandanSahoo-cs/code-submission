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
 
//ai*aj = i+j
//aj = (i+j)/ai
 
void realmsDomain(){
  ll n; cin>>n;
  vector<ll>a(n+1);
 
  for(ll i=1;i<=n;i++){
    cin>>a[i];
  }
 
  ll cnt=0;
 
  for(ll i=1;i<=n;i++){
    ll k=1;
    ll j = a[i]*k-i;
    while(j<=n){
        if(j>i && a[j]*a[i]==i+j) cnt++;
        k++;
        j=a[i]*k-i;
    }
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