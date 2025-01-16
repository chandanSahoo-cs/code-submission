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
ll Good(string s,char c){
    ll l=0,r=s.size()-1;
    ll cnt=0;
    while(l<r){
        if(s[l]!=s[r]){
            if(s[l]==c){
                l++;
                cnt++;
            }
            else if(s[r]==c){
                r--;
                cnt++;
            }
            else{
                return -1 ;
            }
        }
        else{
            l++;
            r--;
        }
    }
 
    return cnt;
}
 
 
void realmsDomain(){
  ll n; cin>>n;
  string s; cin>>s;
 
  // ll l=0,r=n-1;
  ll ans = LLONG_MAX;
  for(ll i=0;i<26;i++){
    ll t = Good(s,char('a'+i));
    if(t!=-1){
        ans = min(ans,t);
    }
  }
 
  if(ans==LLONG_MAX){
    cout<<-1<<"\n";
  }
  else cout<<ans<<"\n";
 
  // while(l<r){
 
  //   if(s[l]!=s[r]){
  //       ll p1 = Good(s.substr(l,r-l+1),s[l]);
  //       ll p2 = Good(s.substr(l,r-l+1),s[r]);
 
  //       if(p1==-1 && p2==-1) cout<<"-1\n";
  //       else if(p1==-1) cout<<p2<<"\n";
  //       else if(p2==-1) cout<<p1<<"\n";
  //       else cout<<min(p1,p2)<<"\n";
 
  //       return;
  //   }
 
  //   l++;
  //   r--;
  // }
  // cout<<0<<"\n";  
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