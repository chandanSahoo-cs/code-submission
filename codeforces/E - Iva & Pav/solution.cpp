/*It is happening, right here and now*/
        
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
 
const int MX = 30;
 
void realmsDomain(){
    ll n; cin>>n;
    vector<ll>a(n);
 
    for(auto &ele:a) cin>>ele;
 
    vector<vector<ll>>b(n+1,vector<ll>(MX,-1));
 
    for(int i=n-1;i>=0;i--){
        int val = a[i];
 
        for(int j=0;j<MX;j++){
            if(val & (1<<j)){
                if(b[i+1][j]!=-1){
                    b[i][j] = b[i+1][j];
                }else b[i][j] = i;
            }else b[i][j]=-1;
        }
    }
 
    ll q; cin>>q;
 
    while(q--){
        ll l,k; cin>>l>>k;
 
        ll ans = n;
        ll buff = -1;
 
        for(int i=MX-1;i>=0;i--){
            if(k&(1<<i)){
                if(b[l-1][i]==-1){
                    ans=-1;
                }else ans = min(ans,b[l-1][i]+1);
            }else{
                if(b[l-1][i]!=-1 && ans!=-1){
                    buff = max(buff,min(ans,b[l-1][i]+1));
                }
            }
        }
 
        cout<<max(buff,ans)<<" ";
    }
    cout<<"\n";
 
    return;
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