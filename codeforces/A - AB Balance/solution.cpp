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
  string s; cin>>s;
  ll strt=0,end=0;
  string t="";
  for(auto ele:s){
    if(t==""){
        t+=ele;
        end++;
        continue;
    }
    else if(t.back()!=ele){
        if(!strt){
            strt=end;
        }
        t+=ele;
        end=1;
    }
    else end++;
  }
  deb(t);
  deb(strt,end);
  if(t.size()%2==0){
    if(s[0]=='a') s[0]='b';
    else s[0]='a';
    cout<<s<<"\n";
  }
  else cout<<s<<"\n";
 
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