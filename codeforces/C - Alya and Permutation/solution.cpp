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
 
ll binExpMod(ll base, ll exp, ll mod) {
    ll result = 1;
    base = base % mod;
    
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    
    return result;
}
 
void realmsDomain(){
  ll n; cin>>n;
  ll k = 0;
  vector<ll>ans;
  ll w = binExpMod(2,__lg(n),mod)-1;
  if(n==w+1){
    for(ll i=2;i<n-2;i++){
        ans.push_back(i);
    }
    ans.push_back(1);
    ans.push_back(n-2);
    ans.push_back(n-1);
    ans.push_back(n);
  }
  else if(n%2==0){
    for(ll i=1;i<n-1;i++){
        if(i!=w){
            ans.push_back(i);
        }
    }
    ans.push_back(n-1);
    ans.push_back(n);
    if(n-1!=w) ans.push_back(w);
 
 
  }
  else{
    for(ll i=2;i<n-1;i++){
        if(i!=3) ans.push_back(i);
    }
    ans.push_back(1);
    ans.push_back(3);
    ans.push_back(n-1);
    ans.push_back(n);
  }
 
  for(ll i=0;i<n;i++){
    if(i%2==0){
        k&=ans[i];
    }
    else k|=ans[i];
  }
 
  cout<<k<<"\n";
  for(auto ele:ans) cout<<ele<<" ";
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