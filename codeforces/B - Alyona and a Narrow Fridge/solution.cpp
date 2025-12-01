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
   ll n,h; cin>>n>>h;
 
   vector<ll>temp(n);
   for(auto &ele:temp) cin>>ele;
 
   ll l=0,r=n-1;
   ll ans=0; 
 
   while(l<=r){
    ll m = r+(l-r)/2;
    vector<ll>a = temp;
    sort(a.begin(),a.begin()+m+1,greater());
    ll tempH = h;
    bool flag=false;
    for(ll j=0;j<m+1;j+=2){
        if(tempH-a[j]<0){
            r=m-1;
            flag=true;
            break;
        }else tempH-=a[j];
    }
    if(!flag){
        l=m+1;
        ans=m+1;
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
 
    // cin>>tsts;    
 
    for(ll testcase = 1 ; testcase <=  tsts ; testcase++ ){
        realmsDomain();
    }
 
    #ifdef chandan
    cerr << "Time : " << fixed << setprecision(6) << ((double)(clock() - time_req)) / CLOCKS_PER_SEC << endl;
    #endif
 
    return 0;
}