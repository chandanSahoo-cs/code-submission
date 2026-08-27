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
vector<ll>ans;  
 
ll dfs(vector<vector<ll>>&adj,vector<ll>&res,ll u){
    ll cnt = adj[u].size();
 
    for(auto v:adj[u]){
        cnt-=dfs(adj,res,v);
    }
 
    if(!cnt && res[u]){
        ans.push_back(u);
    }
 
    return res[u];
}
 
void realmsDomain(){
    ll n; cin>>n;
    vector<vector<ll>>adj(n+1);
    vector<ll>res(n+1);
 
    ll root = -1;
 
    for(ll i=1;i<=n;i++){
        ll par, c; cin>>par>>c;
        if(par==-1){
            root = i;
        }else adj[par].push_back(i);
        res[i] = c;
    }
 
    deb(adj,res,root);
 
    ans.clear();
 
    dfs(adj,res,root);
    sort(all(ans));
 
    if(ans.size()==0){
        cout<<"-1\n";
        return;
    }
 
    for(auto ele:ans) cout<<ele<<" ";
    cout<<"\n";
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