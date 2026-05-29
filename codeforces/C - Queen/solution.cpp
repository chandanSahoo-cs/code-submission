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
 
bool dfs(int n,vector<vector<int>>&adj , vector<int>&compliance, int u,vector<int>&ans){
    int nonComp = compliance[u];
 
    // if(!nonComp) return nonComp;
 
    for(auto &v:adj[u]){
        nonComp &= dfs(n,adj,compliance,v,ans);
    }
 
    if(nonComp) ans.push_back(u);
 
    return compliance[u];
}
 
void realmsDomain(){
    int n; cin>>n;
    vector<int>compliance(n);
    vector<vector<int>>adj(n);
 
    int root = -1;
    for(int i=0;i<n;i++){
        int p,c; cin>>p>>c;
        if(p==-1) root = i;
        else adj[p-1].push_back(i);
 
        compliance[i] = c;
    }
 
    vector<int>ans;
 
    dfs(n,adj,compliance,root,ans);
    sort(ans.begin(),ans.end());
 
    if(ans.size()==0){
        cout<<-1<<"\n";
        return;
    }
    
    for(auto &ele:ans) cout<<ele+1<<" ";
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