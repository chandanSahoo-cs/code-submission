/*It is not the matter of if, it is the matter of when*/
        
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
    ll n; cin>>n;
    vector<ll>a(2*n);
    for(auto &ele:a) cin>>ele;
 
    vector<ll>b;
    sort(all(a));
    ll sum=0;
    for(ll i=1;i<n;i++){
        b.push_back(a[i+n-1]);
        b.push_back(a[i]);
        sum+=a[i+n-1]-a[i];
    }
    deb(b);
    sum+=a[0]+a.back();
    b.push_back(a[0]);
    b.push_back(sum);
    b.push_back(a.back());
 
    for(auto ele:b) cout<<ele<<" ";
    cout<<"\n";
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