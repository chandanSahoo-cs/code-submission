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
 
ll check(ll n,ll f,ll se){
    ll t = se;
    ll cnt = 0;
    ll s = log10(n)+1;
    bool found2=false;
    bool found1=false;
    while(n>0){
        if(t==f && n%10==t && found1){
            found2=true;
            break;
        }
        else if(n%10==t){
            t=f;
            found1=true;
        }
        else cnt++;
        n/=10;
    }
    return found2?cnt:s;
}
 
void realmsDomain(){
  ll n; cin>>n;
  cout<<min({check(n,2LL,5LL),check(n,5LL,0LL),check(n,7LL,5LL),check(n,0LL,0LL)})<<"\n";
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