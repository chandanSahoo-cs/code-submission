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
        // if(j==0){
        //     strt=ele+1;
        //     go=strt;
        // }else{
        //     if(go<=ele){
        //         strt=ele-j+1;
        //         go=ele+1;
        //     }else go++;
        // }
 
void realmsDomain(){
   ll n; cin>>n;
   vector<vector<ll>>a(n);
   vector<ll>mxCave(n);
 
   for(ll i=0;i<n;i++){
    ll k; cin>>k;
    ll mx=1;
    for(ll j=0;j<k;j++){
        ll ele; cin>>ele;
        a[i].push_back(ele);
        mx = max(mx,ele-j+1);
    }
    mxCave[i]=mx;
   }
 
   vector<ll>foo(n);
   iota(all(foo),0LL);
   deb(mxCave);
 
   sort(all(foo),[&](ll i,ll j){
    return mxCave[i]<mxCave[j];
   });
   deb(foo);
 
   vector<int>tot;
 
   for(auto ele:foo){
    for(auto e:a[ele]){
        tot.push_back(e);
    }
   }
 
   deb(tot);
 
 
   ll strt=1;
   ll go=strt;
 
   for(int j=0;j<(ll)tot.size();j++){
    ll ele = tot[j];
    if(j==0){
        strt=ele+1;
        go=strt;
    }else{
        if(go<=ele){
            strt=ele-j+1;
            go=ele+1;
        }else go++;
    }
   }
 
   cout<<strt<<"\n";
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