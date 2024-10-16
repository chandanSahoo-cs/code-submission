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
   string s; cin>>s;
 
   ll cnt=0;
 
   queue<ll>ans;
 
   for(ll i=0;i<n;i++){
    if(s[i]=='L'){
        cnt+=i;
    }
    else cnt+=n-1-i;
   }
 
   for(ll i=0;i<n/2;i++){
    if(s[i]=='L'){
        cnt-=i;
        cnt+=n-1-i;
        ans.push(cnt);
        deb(cnt);
    }
 
    if(s[n-1-i]=='R'){
        cnt-=n-1-(n-1-i);
        cnt+=n-1-i;
        ans.push(cnt);
        deb(cnt);
    }
   }
 
   for(ll i=0;i<n;i++){
    if(!ans.empty()){
        cout<<ans.front()<<" ";
        ans.pop();
    }
    else{
        cout<<cnt<<" ";
    }
   }
   cout<<"\n";
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