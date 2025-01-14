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
  ll n; cin>>n;
  vector<ll>a(n);
  for(auto &ele:a) cin>>ele;
  ll strt = 1,end=n;
  ll l=0,r=n-1;
  bool flagl=false,flagr=false;
  while(l<r){
    if(a[l]==strt){
      l++;
      strt++;
      flagl=true;
    }
    else if(a[l]==end){
      l++;
      end--;
      flagl=true;
    }
 
    if(a[r]==strt){
      r--;
      strt++;
      flagr=true;
    }
    else if(a[r]==end){
      r--;
      end--;
      flagr=true;
    }
 
    if(!flagl && !flagr){
      cout<<l+1<<" "<<r+1<<"\n";
      return;
    }
    flagl=false;
    flagr=false;
  }
 
  cout<<"-1\n";  
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