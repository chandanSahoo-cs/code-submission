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
 
ll getInv(vector<ll>&a){
 
    ll inv = 0;
    ll cnt1=0;
 
    for(auto ele:a){
        if(ele==1) cnt1++;
        else inv+=cnt1;
    }
 
    return inv;
}
 
void realmsDomain(){
   ll n; cin>>n;
   vector<ll>a(n);
 
   for(auto &ele:a) cin>>ele;
 
    ll ans = getInv(a);
 
    for(int i=0;i<n;i++){
        if(a[i]==0){
            a[i]=1;
            ans = max(ans,getInv(a));
            a[i]=0;
            break;
        }
    }
 
    for(int i=n-1;i>=0;i--){
        if(a[i]==1){
            a[i]=0;
            ans = max(ans,getInv(a));
            break;
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