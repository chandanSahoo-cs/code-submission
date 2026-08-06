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
 
void realmsDomain(){
  ll n; cin>>n;
  string s; cin>>s;
  string a = "";
  a+=s[0];
 
  ll cnt0 = 0, cnt1 = 0;
 
  for(ll i=1;i<n;i++){
    if(s[i]!=a.back()) a+=s[i];
    else{
      cnt0+=s[i]=='0';
      cnt1+=s[i]=='1';
    }
  }
 
  deb(a);
 
  if(abs(cnt0-cnt1)<=1){
    cout<<cnt1+cnt0<<"\n";
    return;
  }
 
  if(cnt1<cnt0){
    cnt1+=a.back()=='1';
    if(abs(cnt1-cnt0)>1) cnt1+=a[0]=='1';
  }else{
    cnt0+=a.back()=='0';
    if(abs(cnt1-cnt0)>1) cnt0+=a[0]=='0';
  }
 
  if(abs(cnt0-cnt1)<=1){
    cout<<cnt1+cnt0<<"\n";
    return;
  }
 
  cout<<"-1\n";
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