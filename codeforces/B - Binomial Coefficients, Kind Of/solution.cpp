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
 
ll binExp(ll base, ll exp, ll mod) {
    ll result = 1;
    base = base % mod;
    
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    
    return result;
}
 
 
#ifdef chandan  
#include "starPlatinum.h"
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif
const int mod = 1e9+7;
 
void realmsDomain(){
    ll t; cin>>t;
    vector<ll>n(t),k(t);
    for(auto &ele:n) cin>>ele;
    for(auto &ele:k) cin>>ele;
    for(ll i=0;i<t;i++){
        cout<<binExp(2,k[i],mod)<<"\n";
    }
}
 
 
 
 
int main() {
clock_t time_req = clock();
velociraptor
 
 
#ifdef chandan 
freopen("error.txt", "w", stderr); 
#endif
 
ll tsts = 1 ; 
 
// cin>>tsts;    
 
for(ll testcase = 1 ; testcase <=  tsts ; testcase++ ){
realmsDomain();
}
 
 
 
 
#ifdef chandan
    cerr << "Time : " << fixed << setprecision(6) << ((double)(clock() - time_req)) / CLOCKS_PER_SEC << endl;
#endif
 
    return 0;
}