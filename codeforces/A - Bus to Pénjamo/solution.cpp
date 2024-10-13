#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
#define velociraptor ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);                                             
#define all(v) v.begin(),v.end()
#define lcd(a,b) a*(b/__gcd(a,b))
 
#define ll long long
 
#define SIEVE(MAXN)                                   \
    vector<bool> isPrime(MAXN + 1, true);             \
    void sieveOfEratosthenes()                        \
    {                                                 \
        isPrime[0] = isPrime[1] = false;              \
        for (ll i = 2; i * i <= MAXN; i++)            \
        {                                             \
            if (isPrime[i])                           \
            {                                         \
                for (ll j = i * i; j <= MAXN; j += i) \
                {                                     \
                    isPrime[j] = false;               \
                }                                     \
            }                                         \
        }                                             \
    }
 
#ifdef chandan  
#include "starPlatinum.h"
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif
const int mod = 1e9+7;
 
void realmsDomain(){
    ll n,r; cin>>n>>r;
    vector<ll>store(n);
    for(auto &ele:store) cin>>ele;
    ll tr=r;
    ll cnt=0;
    ll unhappy=0;
    for(ll i=0;i<n;i++){
        cnt+=store[i]-store[i]%2;
        tr-=store[i]/2;
        if(store[i]%2!=0){
            unhappy+=store[i]%2;
        }
        deb(cnt,tr,unhappy);
    }
    if(tr-unhappy>0) cout<<cnt+unhappy<<"\n";
    else{
        cout<<cnt+tr+(tr-unhappy)<<"\n";
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