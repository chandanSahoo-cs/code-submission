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
 
   // ll tot = accumulate(all(a),0LL);
 
   pair<ll,pair<ll,ll>> mxSum = {-mod,{0,0}};
   ll currSum = -mod;
 
   ll l=0,r=0;
 
   for(ll i=0;i<n;i++){
    if(currSum+a[i]<=a[i]){
        l=i;
        r=i;
        currSum = a[i];
    }else{
        currSum+=a[i];
        r++;
    }
    if(mxSum.first<currSum){
        mxSum.first = currSum;
        mxSum.second = {l,r};
    }
   }
 
   pair<ll,ll>temp = {0LL,n-1};
 
   deb(mxSum);
 
   if(mxSum.second==temp){
    cout<<"YES\n";
   }else cout<<"NO\n";
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