/*It is not the matter of if, it is the matter of when*/
        
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
 
void realmsDomain(){
    ll n,m; cin>>n>>m;
    vector<ll>a(n);
    map<ll,ll>mp;
    for(auto &ele:a) cin>>ele , mp[ele%m]++;
 
    ll cnt=0;
    vector<ll>mark(m);
 
    for(auto ele:mp){
        if(mark[ele.first]==1) continue;
        mark[ele.first]=1;
 
        auto it = mp.find((m-ele.first)%m);
 
        if(it!=mp.end()){
            if(it->first==ele.first) cnt++;
            else if(it->second==ele.second){
                cnt+=1;
            }
            else if(it->second > ele.second){
                cnt+=it->second-ele.second;
            }
            else{
                cnt+=ele.second-it->second;
            }
            mark[it->first]=1;
        }
        else{
            cnt+=ele.second;
        }
    }
 
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