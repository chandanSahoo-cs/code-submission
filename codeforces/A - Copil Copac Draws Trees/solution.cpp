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
 
void realmsDomain(){
    ll n; cin>>n;
    vector<pair<ll,ll>>edges(n-1);
 
    for(auto &ele:edges){
        cin>>ele.first>>ele.second;
    }
 
    vector<vector<pair<ll,ll>>>adj(n+1);
 
    for(ll i=0;i<n-1;i++){
        auto [u,v] = edges[i];
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
    }
 
    queue<tuple<ll,ll,ll>>q;
    vector<ll>mark(n+1,0);
    q.push({1,-1,1});
    mark[1]=1;
    ll mx = 1;
 
    while(!q.empty()){
        auto [u,ind,read] = q.front();
        q.pop();
 
        for(auto &[v,i]:adj[u]){
            if(mark[v]) continue;
            if(i<ind){
                mx = max(mx,read+1);
                q.push({v,i,read+1});
            }else q.push({v,i,read});
            mark[v]=1;
        }
    }
 
    cout<<mx<<"\n";
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