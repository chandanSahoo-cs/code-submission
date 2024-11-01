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
    ll x,y,k; cin>>x>>y>>k;
    // if(k<=min(x,y)){
    //     cout<<0<<" "<<0<<" "<<0<<" "<<k<<"\n";
    //     cout<<0<<" "<<0<<" "<<k<<" "<<0<<"\n";
    //     return;
    // }
    // cout<<0<<" "<<k-x<<" "<<x<<" "<<y<<"\n";
    // cout<<0<<" "<<x<<" "<<x<<" "<<0<<"\n";
    cout<<0<<" "<<0<<" "<<min(x,y)<<" "<<min(x,y)<<"\n";
    cout<<0<<" "<<min(x,y)<<" "<<min(x,y)<<" "<<0<<"\n";
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