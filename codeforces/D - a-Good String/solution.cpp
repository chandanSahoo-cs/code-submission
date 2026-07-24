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
 
ll rec(string &s, ll l, ll r, char c){
  // ll n = s.size();
 
  if(l==r) return !(s[l]==c);
 
  ll mid = (l+r)/2;
  
  // left part
 
  ll cntl = 0;
  for(ll i=l;i<=mid;i++){
    if(s[i]!=c) cntl++;
  }
 
  ll p1 = cntl+rec(s,mid+1,r,c+1);
 
  // right part
 
  ll cntr = 0;
  for(ll i=mid+1;i<=r;i++){
    if(s[i]!=c) cntr++;
  }
 
  ll p2 = cntr+rec(s,l,mid,c+1);
 
  return min(p1,p2);
}
 
void realmsDomain(){
    ll n; cin>>n;
    string s; cin>>s;
    cout<<rec(s,0,n-1,'a')<<"\n";
 
    return;
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