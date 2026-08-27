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
 
ll ask(ll i, ll j){
    cout<<"? "<<i<<" "<<j<<endl;
    ll prod; cin>>prod;
    return prod;
}
 
void realmsDomain(){
    vector<ll>arr = {4,8,15,16,23,42};
    map<ll,pair<ll,ll>>mp;
 
    for(ll i=0;i<6;i++){
        for(ll j=i+1;j<6;j++){
            mp[arr[i]*arr[j]] = {arr[i],arr[j]};
        }
    }
 
    vector<ll>ans;
 
    auto [a,b] = mp[ask(1,2)];
    auto [c,d] = mp[ask(2,3)];
 
    if(a==c){
        ans = {b,c,d};
    }else if(b==c){
        ans = {a,c,d};
    }else if(a==d){
        ans = {b,d,c};
    }else{
        ans = {a,b,c};
    }   
 
    ll q = 2;
    ll idx = 3;
 
    while(q--){
        auto [l,r] = mp[ask(idx,idx+1)];
        if(ans.back()==l){
            ans.push_back(r);
        }else{
            ans.push_back(l);
        }
        idx++;
    }
 
    for(ll i=0;i<6;i++){
        bool flag = true;
        for(auto ele:ans){
            if(ele==arr[i]){
                flag=false;
                break;
            }
        }
 
        if(flag){
            ans.push_back(arr[i]);
            break;
        }
    }
 
    cout<<"! ";
 
    for(ll i=0;i<6;i++){
        cout<<ans[i]<<" ";
    }
 
    cout<<endl;    
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