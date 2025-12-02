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
 
void dfs(vector<vector<ll>>&adj,vector<ll>&vis,vector<ll>&color,ll node){
    queue<ll>q;
    q.push(node);
    color[node]=0;
 
    while(!q.empty()){
        ll t = q.front();
        q.pop();
        vis[t]=1;
        for(auto ele:adj[t]){
            if(vis[ele]) continue;
            color[ele]=!color[t];
            q.push(ele);
        }
        deb(color);
    }
}
 
void realmsDomain(){
   ll n; cin>>n;
   vector<pair<ll,ll>>vp(n-1);
   vector<vector<ll>>adj(n+1);
 
   for(auto &ele:vp){
    cin>>ele.first>>ele.second;
    adj[ele.first].push_back(ele.second);
    adj[ele.second].push_back(ele.first);
   }
 
   vector<ll>color(n+1,-1);
   vector<ll>vis(n+1,0);
 
   dfs(adj,vis,color,vp[0].first);
 
   ll white=0,black=0;
 
   for(ll i=0;i<n+1;i++){
    white+=(color[i]==1);
    black+=(color[i]==0);
   }
 
   ll totEdges = white*black;
 
   cout<<totEdges-n+1<<"\n";
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