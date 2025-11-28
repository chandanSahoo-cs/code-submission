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
 
   bool peak=false,trough=false;
   ll strt=a[0]; 
 
   vector<int>ans;
 
   for(ll i=1;i<n;i++){
    if(a[i]>strt && !peak){
        peak=true;
        trough=false;
        ans.push_back(strt);
    }else if(a[i]<strt && !trough){
        trough=true;
        peak=false;
        ans.push_back(strt);
    }
    strt=a[i];
   }
 
   ans.push_back(strt);
 
   cout<<ans.size()<<"\n";
 
   for(auto ele:ans){
    cout<<ele<<" ";
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