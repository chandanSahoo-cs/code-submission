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
 
/*
uni : n
stud : n
for i : 1->n , s[i] skill , u[i] uni
 
 - divide the student acc to uni
 - sort the students within uni
 - 
 
*/
 
void realmsDomain(){
  ll n; cin>>n;
 
  vector<ll>u(n),s(n);
 
  for(auto &ele:u) cin>>ele;
  for(auto &ele:s) cin>>ele;
 
  vector<vector<ll>>uni(n+1);
  
  for(ll i=0;i<n;i++){
    uni[u[i]].push_back(s[i]);
  }
 
 
  vector<ll>stud(n+1);
 
  for(ll i=1;i<=n;i++){
    sort(all(uni[i]),greater());
 
    ll m = uni[i].size();
 
    for(ll j=1;j<m;j++){
      uni[i][j]+=uni[i][j-1];
    }
 
    for(ll j=1;j<=m;j++){
      stud[j]+=uni[i][((m/j)*j)-1];
    }
  }
 
  for(ll i=1;i<=n;i++){
    cout<<stud[i]<<" \n"[i==n];
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