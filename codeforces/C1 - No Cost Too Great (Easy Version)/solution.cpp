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
 
void realmsDomain(int t){
   ll n; cin>>n;
   vector<ll>a(n),b(n);
 
   for(auto &ele:a) cin>>ele;
   for(auto &ele:b) cin>>ele;
 
    // if(t==114){
    //     cout<<n<<":";
    //     for(auto ele:a) cout<<ele<<"-";
    //     return;    
    // }
 
   set<ll>st;
 
   for(auto ele:a){
    if(st.find(ele)!=st.end() && ele!=1){
        cout<<0<<"\n";
        return;
    }else{
        if(ele!=1) st.insert(ele);
    }
 
    for(ll i=2;i*i<=ele;i++){
        if((ele%i)==0){
            if(st.find(i)!=st.end() || st.find(ele/i)!=st.end()){
                cout<<0<<"\n";
                return;
            }else{
                st.insert(i);
                st.insert(ele/i);
            }
        }
    }
   }
   deb(st);
 
   for(auto ele:a){
    int val = ele+1;
    deb(val);
    if(st.find(val)!=st.end()){
        cout<<1<<"\n";
        return;
    }
    for(ll i=2;i*i<=(val);i++){
 
        if((val)%i==0){
            if(st.find(i)!=st.end() || st.find(val/i)!=st.end()){
                deb(i);
                cout<<1<<"\n";
                return;
            }
        }
    }
   }
 
   cout<<2<<"\n"; 
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
        realmsDomain(testcase);
    }
 
    #ifdef chandan
    cerr << "Time : " << fixed << setprecision(6) << ((double)(clock() - time_req)) / CLOCKS_PER_SEC << endl;
    #endif
 
    return 0;
}