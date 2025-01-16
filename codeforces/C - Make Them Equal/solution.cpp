/*It is not the matter of if, it is the matter of when*/
        
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
    char c; cin>>c;
    string s; cin>>s;
 
    for(ll i=1;i<=n;i++){
        bool flag=true;
        for(ll j=i;j<=n;j+=i){
            if(s[j-1]!=c){
                flag=false;
                break;
            }
        }
        if(flag){
            if(i==1){
                cout<<0<<"\n";
                return;
            }
            cout<<1<<"\n";
            cout<<i<<"\n";
            return;
        }
    }
    // set<ll>st;
 
    // for(ll i=0;i<n;i++){
    //     if(s[i]!=c){
    //         st.insert(i+1);
    //     }
    // }
    // if(st.size()==0){
    //     cout<<"0\n";
    //     return;
    // }
    // deb(st);
    // for(ll i=2;i<=n;i++){
    //     bool flag=true;
    //     for(ll j=i;j<=n;j+=i){
    //         if(st.find(j)!=st.end()){
    //             flag=false;
    //             break;
    //         }
    //     }
 
    //     if(flag){
    //         cout<<"1\n";
    //         cout<<i<<"\n";
    //         return;
    //     }
    // }
 
 
    cout<<2<<"\n";
    cout<<n<<" "<<n-1<<"\n";
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