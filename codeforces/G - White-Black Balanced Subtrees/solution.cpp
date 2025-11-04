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
 
pair<int,int>rec(vector<vector<int>>&adj,string &s, ll node, ll &cnt){
    ll black=0, white=0;
 
    for(auto ele:adj[node]){
        pair<int,int>pr = rec(adj,s,ele,cnt);
        black+=pr.first;
        white+=pr.second;
    }
 
    if(s[node]=='W') white++;
    else black++;
 
    if(black==white) cnt++;
 
    return {black,white};
}
 
void realmsDomain(){
   ll n; cin>>n;
   vector<ll>a(n-1);
   for(auto &ele:a) cin>>ele;
   // deb(a);
   string s; cin>>s;
    
    vector<vector<int>>adj(n);
    for(ll i=0;i<n-1;i++){
        adj[a[i]-1].push_back(i+1);
    }
 
    ll cnt=0; 
    rec(adj,s,0,cnt);
 
    cout<<cnt<<"\n";
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