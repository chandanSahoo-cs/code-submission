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
 
/*
 
A major learning from this question
-> Think the solution before implementing, part by part krna is dangerouse to your rank
-> Tujhe aata hai mind ko shaant rkha kr, and you will become CM very soon :)
 
*/
 
 
ll findMax(vector<ll>&v,ll x){
    ll n = v.size();
    if(n==0) return 0;
    ll len = 0;
    sort(all(v));
 
    ll sum=0;
    for(ll i=0;i<n;i++){
        sum+=v[i];
        if(sum<=x){
            len = max(i+1,len);
        }
    }
    return len;
}
 
 
void realmsDomain(){
    ll n,k,x; cin>>n>>k>>x;
    vector<ll>a(n);
    for(auto &ele:a) cin>>ele;
    sort(all(a));
 
    vector<ll>need;
    for(ll i=1;i<n;i++){
        if(a[i]-a[i-1]>x){
            ll t = a[i]-a[i-1];
            need.push_back((t+x-1)/x-1);
        }
    }
    deb(need);
    deb(a);
    ll ans = need.size()-findMax(need,k);
    deb(ans);
    cout<<ans+1<<"\n";   
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