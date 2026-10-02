/*It is happening, right here and now*/
        
#include "bits/stdc++.h"
using namespace std;
 
#define velociraptor ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);                                             
#define all(v) v.begin(),v.end()
#define lcd(a,b) a*(b/__gcd(a,b))
#define ll long long
 
const ll mod = 2e9;
 
#ifdef chandan  
#include "starPlatinum.h"
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif
 
/*
    - if a[i]>=b[i] :
        we have to carry access from a[i], double it and give it
        to a[i+1];
    - if a[i]<b[i]:
        we can't go ahead
*/
 
void realmsDomain(){
  ll n; cin>>n;
 
  vector<ll>a(n),b(n);
 
  for(auto &ele:a) cin>>ele;
  for(auto &ele:b) cin>>ele;
 
  ll steps = 0;
  ll carry = 0;
 
  for(ll i=0;i<n;i++){
    a[i]+=carry;
    if(b[i]>a[i]){
        cout<<"-1\n";
        return;
    }else{
        steps += a[i]-b[i];
        carry = 2*(a[i]-b[i]);
    }
 
    if(carry>mod){
        cout<<"-1\n";
        return;
    }
  }
 
  if(carry>0){
    cout<<"-1\n";
  }else cout<<steps<<"\n";
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