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
    private : 
    vector<int>parent,mx;
 
    public : 
    DSU(int n, vector<int>nums){
        parent.resize(n),
        mx = nums;
 
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
 
    int findParent(int u){
        if(parent[u]==u) return u;
        return parent[u] = findParent(parent[u]);
    }
 
    void unite(int u,int v){
        int ult_u = findParent(u);
        int ult_v = findParent(v);
 
        if(ult_u==ult_v) return;
 
        if(mx[ult_u]>mx[ult_v]){
            parent[ult_v] = ult_u;
        }else{
            parent[ult_u] = ult_v;
        }
    }
};
 
void realmsDomain(){
    int n; cin>>n;
    vector<int>nums(n);
    for(auto &ele:nums) cin>>ele;
 
    DSU ds(n,nums);
 
    vector<int>prefMx(n),suffMn(n);
 
    prefMx[0] = nums[0];
    suffMn[n-1] = nums[n-1];
 
    for(int i=1;i<n;i++){
        prefMx[i] = max(prefMx[i-1],nums[i]);
    }
 
    for(int i=n-2;i>=0;i--){
        suffMn[i] = min(suffMn[i+1],nums[i]);
    }
 
    for(int i=n-2;i>=0;i--){
        if(prefMx[i]>suffMn[i+1]){
            ds.unite(i,i+1);
        }
    }
 
    vector<int>ans(n);
 
    for(int i=0;i<n;i++){
        ans[i] = nums[ds.findParent(i)];
        cout<<ans[i]<<" \n"[i==n-1];
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
 
    cin>>tsts;    
 
    for(ll testcase = 1 ; testcase <=  tsts ; testcase++ ){
        realmsDomain();
    }
 
    #ifdef chandan
    cerr << "Time : " << fixed << setprecision(6) << ((double)(clock() - time_req)) / CLOCKS_PER_SEC << endl;
    #endif
 
    return 0;
}