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
  ll n,r,b; cin>>n>>r>>b;
  ll p = b+1;
  ll m = (r+p-1)/p+1;
  string s = "";
 
  for(ll i=1;i<=n;i++){
    if(i%m==0){
      s+='B';
      b--;
    }
    else{
      if(r) s+='R',r--;
      else break;
    }
  }
  ll i=0;
  while(b && i<(ll)s.size()){
    if(s[i]!='B' && (i==0 ||  s[i-1]!='B')) cout<<"B",b--;
    cout<<s[i];
    i++;
  }
  while(i<(ll)s.size()){
    cout<<s[i];
    i++;
  }
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