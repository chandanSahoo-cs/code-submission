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
 
/*
-> Firstly find the first index where a[i]!=a[j] && last index where a[i]!=a[j]
-> after then check how many index before and after first and last index respectively are sorted
-> they will your new first and last index 
-> print the ans
*/
 
 
void realmsDomain(){
  ll n; cin>>n;
  vector<ll>a(n),b(n);
  for(auto &ele:a) cin>>ele;  
  for(auto &ele:b) cin>>ele;
 
  ll l=0,r=n-1;
 
  while(a[l]==b[l]) l++;
  while(b[l]>=b[l-1] && l>0) l--;
  while(a[r]==b[r]) r--;
  while(b[r]<=b[r+1] && r<n-1) r++;
 
  cout<<l+1<<" "<<r+1<<"\n";   
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