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
    vector<ll>a(2*n);
    for(auto &ele:a) cin>>ele;
 
    vector<ll>even={0},odd={0};
 
    for(ll i=0;i<2*n-1;i++){
        if(i%2) odd.push_back(a[i+1]-a[i]+odd.back());
        else even.push_back(a[i+1]-a[i]+even.back());
    }
 
    deb(even,odd);
 
    ll e = even.size();
    ll o = odd.size();
    ll l=0,r=2*n-1;
 
    ll keep=0;
 
    for(ll i=0;i<n;i++){
        ll sum=0;
        ll fac = i/2;
 
        if(i%2==0){
            sum = even[e-1-fac]-even[0+fac]+keep;
        }else{
            sum = odd[o-1-fac]-odd[0+fac]+keep;
        }
        cout<<sum<<" \n"[i==n-1];
 
        keep += a[r]-a[l];
        l++;r--;
    }
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