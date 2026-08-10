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
 
bool check(string s){
  deb(s);
  ll n = s.size();
  for(ll i=2;i<n;i++){
    if(s[i]=='?'){
      if(s[i-2]=='0') s[i]='1';
      else s[i]='0';
    }else{
      if(s[i-2]==s[i]) return false;
    }
  }
 
  return true;
}
 
void realmsDomain(){
  ll n; cin>>n;
  string s; cin>>s;
 
  ll cnt = 0;
 
  // 00
  if((s[0]=='0' || s[0]=='?') && (s[1]=='0' || s[1]=='?')){
    if(check("00"+s.substr(2))) cnt++;
  }
 
  // 11 
  if((s[0]=='1' || s[0]=='?') && (s[1]=='1' || s[1]=='?')){
    if(check("11"+s.substr(2))) cnt++;
  }
 
  // 01
  if((s[0]=='0' || s[0]=='?') && (s[1]=='1' || s[1]=='?')){
    if(check("01"+s.substr(2))) cnt++;
  }
 
  // 10
  if((s[0]=='1' || s[0]=='?') && (s[1]=='0' || s[1]=='?')){
    if(check("10"+s.substr(2))) cnt++;
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