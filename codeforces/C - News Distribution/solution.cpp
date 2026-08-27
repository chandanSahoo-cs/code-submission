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
 
class DSU{
    vector<ll>parent,sz;
public:
    DSU(ll n){
        parent.resize(n+1);
        sz.resize(n+1);
 
        for(int i=0;i<=n;i++){
            parent[i]=i;
            sz[i]=1;
        }
    }
 
    ll findParent(ll u){
        if(parent[u]==u) return u;
        return parent[u] = findParent(parent[u]);
    }
 
    void unite(ll u, ll v){
        ll ult_u = findParent(u);
        ll ult_v = findParent(v);
 
        if(ult_u==ult_v) return;
 
        if(sz[ult_u]>sz[ult_v]){
            parent[ult_v] = ult_u;
            sz[ult_u]+=sz[ult_v];
        }else{
            parent[ult_u] = ult_v;
            sz[ult_v]+=sz[ult_u];
        }
 
        return;
    }
 
    ll mem(ll u){
        ll ult_u = findParent(u);
        return sz[ult_u];
    }
};
 
void realmsDomain(){
    ll n,m; cin>>n>>m;
 
    DSU ds(n);
 
    for(ll i=0;i<m;i++){
        ll sz; cin>>sz;
        vector<ll>temp(sz);
        for(auto &ele:temp) cin>>ele;
 
        for(ll i=1;i<sz;i++){
            ds.unite(temp[i],temp[i-1]);
        }
    }
 
    for(ll i=1;i<=n;i++){
        cout<<ds.mem(i)<<" \n"[i==n];
    }
 
    return;
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