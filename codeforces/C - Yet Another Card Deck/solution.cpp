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
  vector<ll>cards(51,0);  
  for(ll i=0;i<n;i++){
    cin>>a[i];
    if(!cards[a[i]]) cards[a[i]]=i+1;
  }
  deb(cards);
  while(q--){
    ll t; cin>>t;
    cout<<cards[t]<<" ";
    ll h = cards[t];
 
    for(ll i=1;i<51;i++){
        if(cards[i]<h){
            cards[i]++;
        }
    }
    cards[t]=1;
  }
}
 
int main() {
    clock_t time_req = clock();
    velociraptor
 
 
    #ifdef chandan 
    freopen("error.txt", "w", stderr); 
    #endif
 
    ll tsts = 1 ; 
 
    // cin>>tsts;    
 
    for(ll testcase = 1 ; testcase <=  tsts ; testcase++ ){
        realmsDomain();
    }
 
    #ifdef chandan
    cerr << "Time : " << fixed << setprecision(6) << ((double)(clock() - time_req)) / CLOCKS_PER_SEC << endl;
    #endif
 
    return 0;
}