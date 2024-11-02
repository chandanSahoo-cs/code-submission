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
 
void realmsDomain(ll t){
  ll n; cin>>n;
  vector<ll>a(n);
  map<ll,ll>req;
  map<ll,ll>mark;
  map<ll,ll>freq;
  for(auto &ele:a) cin>>ele,freq[ele]++;
  // if(t==465){
  //   cout<<n<<"-";
  //   for(auto ele:a) cout<<ele<<"-";
  //   return;
  // }  
  sort(all(a)); 
  for(ll i=n-1;i>=0;i--){
    if(mark[a[i]]) continue;
    ll cnt=0;
    auto it = upper_bound(all(a),(a[i]+1)/2);
    if(it!=a.end()){
        ll val = it-a.begin();
        if(val==0) cnt+=0;
        else if(a[val-1]==(ll)(a[i]+1)/2){
            cnt+=val-1;
 
            if(a[val-1]+a[val]>a[i]){
                if(2*a[val-1]>a[i]){
                    cnt-=freq[a[val-1]]-1;;
                }
            }
 
        }
        else if(a[val-1]!=(ll)(a[i]+1)/2){
            cnt+=val;
            if(a[val-1]+a[val]>a[i]){
                if(2*a[val-1]<=a[i]){
                    cnt-=1;
                }else{
                    cnt-=freq[a[val-1]];
                }
            }
            // if(2*a[val-1]<a[i]){
            //     cnt+=freq[a[val-1]]-1;
            // }
        }
        deb(val);
        deb(cnt);
    }
    cnt+=n-1-i;
    req[a[i]] = cnt;
    mark[a[i]] = 1;
  }
  deb(req);
  ll ans=LLONG_MAX;
  for(auto ele:req){
    ans=min(ans,ele.second);
  }  
  cout<<ans<<"\n";
 
//     ll n; cin>>n;
//     vector<ll>a(n);
//     for(auto &ele:a) cin>>ele;
//     ll mn = LLONG_MAX;
 
//     ll e = n-1, s=0;
 
//     while(s<e){
//         ll t = (a[e]+1)/2;
//         while(a[s]<t){}
//     }    
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