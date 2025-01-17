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
  string s; cin>>s;
 
  for(ll i=0;i<26;i++){
    string k = "";
    k+=char('a'+i);
    deb(k);
    if(s.find(k)==string::npos){
        cout<<k<<"\n";
        return;
    }
  }
 
  for(ll i=0;i<26;i++){
    for(ll j=0;j<26;j++){
        string k = "";
        k+=char('a'+i);
        k+=char('a'+j);
        if(s.find(k)==string::npos){
            cout<<k<<"\n";
            return;
        }
    }
  }
 
  for(ll i=0;i<26;i++){
    for(ll j=0;j<26;j++){
        for(ll l=0;l<26;l++){
            string k = "";
            k+=char('a'+i);
            k+=char('a'+j);
            k+=char('a'+l);
            if(s.find(k)==string::npos){
                cout<<k<<"\n";
                return;
            }
        }
    }
  }
 
 
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