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
  ll n,m; cin>>n>>m;
  string s; cin>>s;
  vector<vector<ll>>a(n,vector<ll>(m));
 
  for(ll i=0;i<n;i++){
    for(ll j=0;j<m;j++){
      cin>>a[i][j];
    }
  }
 
  vector<ll>colSum,rowSum;
 
  for(ll i=0;i<n;i++){
    ll k = 0;
    for(ll j=0;j<m;j++){
      k+=a[i][j];
    }
    rowSum.push_back(k);
  }
 
  for(ll i=0;i<m;i++){
    ll k=0;
    for(ll j=0;j<n;j++){
      k+=a[j][i];
    }
    colSum.push_back(k);
  }
 
  deb(rowSum,colSum);
 
 
  ll i=0,x=0,y=0;
 
  while(i<(ll)s.size()){
    if(s[i]=='D'){
      a[x][y] = -1*rowSum[x];
      colSum[y]+=a[x][y];
      x++;
    }
    else{
      a[x][y] = -1*colSum[y];
      rowSum[x]+=a[x][y];
      y++;
    }
    i++;
  }
 
  if(s.back()=='D'){
    a[x][y] = -1*colSum[y];
  }
  else{
    a[x][y] = -1*rowSum[x];
  }
 
  for(ll i=0;i<n;i++){
    for(ll j=0;j<m;j++){
      cout<<a[i][j]<<" \n"[j==m-1];
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