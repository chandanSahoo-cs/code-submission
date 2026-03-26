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
   vector<ll>a(n);
 
   for(auto &ele:a) cin>>ele;
 
   sort(all(a));
 
   ll diff = INT_MAX;
   ll l=-1,r=-1;
 
   for(int i=0;i<n-1;i++){
    if(a[i+1]-a[i]<diff){
        diff=a[i+1]-a[i];
        l=i,r=i+1;
    }
   }
 
   for(int i=r;i<=n-1;i++){
    if(i==r) cout<<a[l]<<" ";
    else cout<<a[i]<<" ";
   }
 
   for(int i=0;i<=l;i++){
    if(i==l) cout<<a[r]<<" ";
    else cout<<a[i]<<" ";
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