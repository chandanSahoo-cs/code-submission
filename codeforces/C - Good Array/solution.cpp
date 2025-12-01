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
   ll mx = 0;
   for(auto &ele:a) {
    cin>>ele;
    mx = max(mx,ele);
   }
 
   ll sum = accumulate(all(a),0LL); 
   vector<ll>store(n);
   vector<ll>mp(1e6+1,0);
 
   for(ll i=0;i<n;i++){
    store[i]=sum-a[i];
    mp[a[i]]++;
   }
 
   vector<ll>ans;
 
   for(ll i=0;i<n;i++){
    if(!(store[i]&1) && store[i]/2<=1e6 && mp[store[i]/2]-(a[i]==store[i]/2)>0){
        ans.push_back(i+1);
    }
   }
 
   cout<<ans.size()<<"\n";
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
 
    // cin>>tsts;    
 
    for(ll testcase = 1 ; testcase <=  tsts ; testcase++ ){
        realmsDomain();
    }
 
    #ifdef chandan
    cerr << "Time : " << fixed << setprecision(6) << ((double)(clock() - time_req)) / CLOCKS_PER_SEC << endl;
    #endif
 
    return 0;
}