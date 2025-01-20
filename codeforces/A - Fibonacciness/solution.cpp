/*It is not the matter of if, it is the matter of when*/
        
#include "bits/stdc++.h"
using namespace std;
 
#define velociraptor ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);                                             
#define all(v) v.begin(),v.end()
#define lcd(a,b) (a*b)/__gcd(a,b)
#define ll long long
 
const int mod = 1e9+7;
 
#ifdef chandan  
#include "starPlatinum.h"
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif
 
ll fibo(ll a,ll b,ll c,ll d,ll e){
  ll cnt=0;
  if(a+b==c) cnt++;
  if(b+c==d) cnt++;
  if(c+d==e) cnt++;
  return cnt;
}
 
void realmsDomain(){
  ll a,b,d,e; cin>>a>>b>>d>>e;
 
  ll mx = 0;
  for(ll i=-1e5;i<=1e5;i++){
    mx = max(mx,fibo(a,b,i,d,e));
  }
 
  cout<<mx<<"\n";  
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