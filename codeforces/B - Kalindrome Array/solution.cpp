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
 
vector<ll>clean(vector<ll>&a,ll ele){
    vector<ll>b;
    for(ll i=0;i<(ll)a.size();i++){
        if(a[i]!=ele) b.push_back(a[i]);
    }
    return b;
}
 
bool isPalindrome(vector<ll>&a){
    ll l=0,r=a.size()-1;
 
    while(l<r){
        if(a[l]!=a[r]) return false;
        l++,r--;
    }
 
    return true;
}
 
void realmsDomain(){
  ll n; cin>>n;
  vector<ll>a(n);
  for(auto &ele:a) cin>>ele;
  ll l=0,r=n-1;
  bool flag=true;  
  while(l<r){
    if(a[l]!=a[r]){
        vector<ll>b = clean(a,a[l]);
        vector<ll>c = clean(a,a[r]);
        if(!isPalindrome(b) && !isPalindrome(c)) flag=false;
        break;
    }
    l++;
    r--;
  }
 
  if(flag) cout<<"YES\n";
  else cout<<"NO\n";  
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