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
  vector<ll>a(n);
  vector<ll>pos;
  multiset<ll>st;
 
  ll sum = 0;
 
  for(auto &ele:a){
    cin>>ele;
    sum+=ele;
 
    if(ele<=0){
      st.insert(abs(ele));
    }else pos.push_back(ele);
  }
 
 
  if(sum<=0){
    cout<<"-1\n";
    return;
  }
 
  sort(all(pos));
 
  vector<ll>b;
  ll i = 0;
 
  while(i<pos.size()){
    if(i==0) b.push_back(pos[i++]);
    else b.push_back(b.back()+pos[i++]);
 
    while(!st.empty() && st.upper_bound(b.back()-1)!=st.begin()){
      auto it = prev(st.upper_bound(b.back()-1));
      b.push_back(b.back()-(*it));
      st.erase(it);
    }    
  }
 
  for(auto ele:b) cout<<ele<<" ";
  cout<<"\n";
 
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