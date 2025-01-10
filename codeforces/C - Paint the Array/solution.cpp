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
    ll n; cin>>n;
    vector<ll>a(n);
    for(auto &ele:a) cin>>ele;
    ll gcd1 = a[0];   
    for(ll i=2;i<n;i+=2){
        gcd1=__gcd(gcd1,a[i]);
        deb(i);
    }
    deb(gcd1);
 
    ll gcd2 = a[1];
 
    for(ll i=3;i<n;i+=2){
        gcd2=__gcd(gcd2,a[i]);
    }
 
    bool flag1=true,flag2=true;
 
    for(ll i=1;i<n;i+=2){
        if(a[i]%gcd1==0){
            flag1=false;
            break;
        }
    }
 
    for(ll i=0;i<n;i+=2){
        if(a[i]%gcd2==0){
            flag2=false;
            break;
        }
    }
 
    if(flag1) cout<<gcd1<<"\n";
    else if(flag2) cout<<gcd2<<"\n";
    else cout<<0<<"\n";
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