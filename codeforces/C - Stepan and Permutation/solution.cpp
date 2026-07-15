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
private:
public:
    vector<ll>parent,sz;
    DSU(ll n){
        parent.resize(n);
        sz.resize(n);
 
        for(ll i=0;i<n;i++){
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
 
        if(ult_u>ult_v){
            parent[ult_v] = ult_u;
            sz[ult_u] += sz[ult_v]; 
        }else{
            parent[ult_u] = ult_v;
            sz[ult_v] += sz[ult_u];
        }
 
        return;
    }
 
    bool check(ll u, ll v){
        return findParent(u)==findParent(v);
    }
};
 
void realmsDomain(){
  ll n,x,y; cin>>n>>x>>y;
  vector<ll>a(n);
 
  for(auto &ele:a) cin>>ele;
 
  if(x==1 || y==1){
    cout<<"YES\n";
    return;
  }
 
  unordered_map<ll,ll>mp;
 
  for(ll i=0;i<n;i++){
    mp[a[i]]=i;
  }
 
  vector<ll>mark(n,0);
  queue<ll>q;
 
  DSU ds(n);
 
  for(ll i=0;i<n;i++){
    if(mark[i]) continue;
    q.push(i);
    mark[i]=1;
 
    // deb(ds.parent); 
    while(!q.empty()){
        ll u = q.front(); q.pop();
 
        if(u+x<n){
 
            if(!mark[u+x]){
                q.push(u+x);
                mark[u+x]=1;
            }
 
            ds.unite(u,u+x);
        }
 
        if(u+y<n){
 
            if(!mark[u+y]){
                q.push(u+y);
                mark[u+y]=1;
            }
 
            ds.unite(u,u+y);
        }
    }
  }
 
 
  for(ll i=0;i<n;i++){
    ll u = i, v = mp[i+1];
    // deb(u,v);
    if(!ds.check(u,v)){
        cout<<"NO\n";
        return;
    }
  }
 
  cout<<"YES\n";  
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