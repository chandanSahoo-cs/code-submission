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
 
void add(set<ll>&st,ll i,string &s){
    ll n = s.size();
    if(i>=0 && i<n-3){
        if(s[i] == '1' && s[i+1] == '1' && s[i+2] == '0' && s[i+3] == '0'){
            st.insert(i);
        }
        else{
            st.erase(i);
        }
    }
}
 
void realmsDomain(){
  string s;cin>>s;
  set<ll>st;
  ll n = s.size();
  ll q; cin>>q;
  for(ll i=0;i<n-3;i++){
    add(st,i,s);
  }
  for(ll j=0;j<q;j++){
    ll i,v; cin>>i>>v;
    --i;
    s[i] = char('0'+v);
    deb(s);
    for(ll k = max(0LL,i-3);k<=min(i,n-4);k++){
        add(st,k,s);
    }
    if(st.size()){
        cout<<"YES"<<"\n";
    }
    else cout<<"NO"<<"\n";
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