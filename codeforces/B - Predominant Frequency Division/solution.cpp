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
 
void realmsDomain(ll t){
  ll n; cin>>n;
  vector<ll>a(n);
 
  for(auto &ele:a) cin>>ele;
 
  ll cnt1 = 0, cnt2 = 0, cnt3 = 0;
  ll j = -1, k = -1;
 
  for(ll i=0;i<n-2;i++){
    cnt1+=a[i]==1;
    cnt2+=a[i]==2;
    cnt3+=a[i]==3;    
 
    if(cnt1>=cnt2+cnt3){
      j = i+1;
 
      while(j<n-2 && cnt1>=cnt2+cnt3 && a[j]!=1 && a[j]!=2){
        cnt1+=a[j]==1;
        cnt2+=a[j]==2;
        cnt3+=a[j]==3;
        j++;
      }
 
      if(cnt1<cnt2+cnt3){
        j--;
      }
 
      cnt1=0,cnt2=0,cnt3=0;
      break;
    }
  }
 
  deb(j);
  if(j==-1){
    cout<<"NO\n";
    return;
  }
 
  for(;j<n-1;j++){
    cnt1+=a[j]==1;
    cnt2+=a[j]==2;
    cnt3+=a[j]==3;
 
    if(cnt1+cnt2>=cnt3){
      k = j+1;
      break;
    }
  }
 
  if(k==-1){
    cout<<"NO\n";
    return;
  }
 
  cout<<"YES\n";
 
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
        realmsDomain(testcase);
    }
 
    #ifdef chandan
    cerr << "Time : " << fixed << setprecision(6) << ((double)(clock() - time_req)) / CLOCKS_PER_SEC << endl;
    #endif
 
    return 0;
}