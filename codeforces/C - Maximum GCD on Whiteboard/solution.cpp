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
   ll n,k; cin>>n>>k;
   vector<ll>a(n);
   vector<ll>freq(n+1);
 
   for(auto &ele:a){
    cin>>ele;
    freq[ele]++;
   }
 
   for(ll i=1;i<=n;i++){
    freq[i]+=freq[i-1];
   }
 
   deb(freq);
 
   int ans=1;
 
   for(int i=2;i<=n;i++){
    int good = freq[i]-freq[i-1];
 
    if(4*i<=n){
        good += n-freq[4*i-1];
    }
 
    if(2*i<=n){
        good += freq[2*i]-freq[2*i-1];
    }
 
    if(3*i<=n){
        good +=freq[3*i]-freq[3*i-1];
    }
 
    if(n-good<=k){
        ans = i;
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