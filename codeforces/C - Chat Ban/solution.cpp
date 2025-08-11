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
 
ll calBefore(ll k){
    return (k*(k+1))/2;
}
 
ll calcAfter(ll m,ll k){
    return calBefore(k)+((k-m)*(k-1+m))/2;
}
 
 
void realmsDomain(){
    ll k,x; cin>>k>>x;
 
    ll l=1,r=k;
    ll ans=2*k-1;
 
    if(x>calBefore(k)){
        l=k-1,r=1;
 
        while(l>=r){
            ll m = r+(l-r)/2;
            if(x<=calcAfter(m,k)){
                ans=min(ans,2*k-m);
                r=m+1;
            }else l=m-1;
        }
 
        cout<<ans<<"\n";
 
        return;
    }
 
    while(l<=r){
        ll m = r+(l-r)/2;
        if(x<=calBefore(m)){
            ans=min(ans,m);
            r=m-1;
        }else l=m+1;
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