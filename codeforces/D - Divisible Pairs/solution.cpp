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
    ll n,x,y; cin>>n>>x>>y;
    map<pair<ll,ll>,ll>mp;
 
    vector<ll>a(n);
    for(auto &ele:a){
        cin>>ele;
        mp[{ele%x,ele%y}]++;
    }
 
    ll cnt=0;
 
    for(ll i=0;i<n;i++){
        ll ele = a[i];
        pair<ll,ll>spr={ele%x,ele%y};
        pair<ll,ll>dpr={(x-ele%x)%x,ele%y};
 
 
        if(mp.find(dpr)!=mp.end()){
            cnt+=mp[dpr]-(spr==dpr);
        }
        mp[spr]--;
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