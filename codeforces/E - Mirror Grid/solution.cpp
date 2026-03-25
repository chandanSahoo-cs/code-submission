/*It is happening, right here and now*/
        
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
 
void realmsDomain(){
   ll n; cin>>n;
   vector<string>a(n);
 
   for(auto &ele:a) cin>>ele;
 
    ll ans = 0;
 
   for(ll i=0;i<n/2;i++){
    for(ll j=i;j<n-1-i;j++){
        ll tl = (a[i][j]=='1');
        ll tr = (a[j][n-1-i]=='1');
        ll bl = (a[n-1-j][i]=='1');
        ll br = (a[n-1-i][n-1-j]=='1');
 
        ll cnt = tl+tr+bl+br;
 
        ans+=min(4-cnt,cnt);
    }
   } 
 
   cout<<ans<<"\n";
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