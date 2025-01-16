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
->Firstly it is better to sort and take the prefix the sum of the array to get maximum
->then check which index have less or equal to x cash
->subtract it from x
->now for the remaining value of x check how many days it can sustain on that index, add the number of packs 
and increase the days
->repeat the process until i becomes -1
*/
 
void realmsDomain(){
  ll n,x; cin>>n>>x;
  vector<ll>a(n);
  for(auto &ele:a) cin>>ele;
  sort(all(a));
 
  for(ll i=1;i<n;i++){
    a[i]+=a[i-1];
  }
 
  ll i=n-1;
  ll days=0,packs=0;
 
  while(i>=0){
    if(a[i]+(i+1)*days<=x){
      packs+=i+1;
      days++;
      ll t = x-a[i]-(i+1)*(days-1);
      packs+=(i+1)*(t/(i+1));
      days+=t/(i+1);
    }
    i--;
  }
 
  cout<<packs<<"\n";  
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