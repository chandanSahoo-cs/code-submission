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
 
set<pair<ll,ll>>generateCorners(ll a,ll b,ll x,ll y){
    set<pair<ll,ll>>vp;
    vp.insert({x+a,y+b});
    vp.insert({x+a,y-b});
    vp.insert({x-a,y+b});
    vp.insert({x-a,y-b});
    vp.insert({x+b,y+a});
    vp.insert({x+b,y-a});
    vp.insert({x-b,y+a});
    vp.insert({x-b,y-a});
    return vp;
 
}
 
void realmsDomain(){
    ll a,b,kx,ky,qx,qy; cin>>a>>b>>kx>>ky>>qx>>qy;
    set<pair<ll,ll>> vk = generateCorners(a,b,kx,ky);
    deb(vk);
    set<pair<ll,ll>> vq = generateCorners(a,b,qx,qy);
    deb(vq);
    ll cnt=0;
    
    for(auto ele:vk){
        for(auto eleq:vq){
            if(ele==eleq){
                cnt++;
                deb(eleq);
            }
        }
    }
 
    cout<<cnt<<"\n";
 
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