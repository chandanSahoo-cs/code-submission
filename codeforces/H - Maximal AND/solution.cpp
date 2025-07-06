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
 
void fillBits(vector<ll>&bits,ll ele){
    ll cnt=0;
    while(cnt<=31){
        if(ele & (1<<cnt)){
            bits[cnt]++;
        }
        cnt++;
    }
}
 
 
void realmsDomain(){
    ll n,k; cin>>n>>k;
    vector<ll>a(n);
    vector<ll>bits(32);
 
    for(auto &ele:a){
        cin>>ele;
        fillBits(bits,ele);
    }
 
    ll ans=0;
 
    for(ll i=30;i>=0;i--){
        if(bits[i]+k>=n && k>=0){
            k-=n-bits[i];
            ans+=(1<<i);
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