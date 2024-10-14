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
 
#define BIN_EXP(a, b)         \
    ({                        \
        int res = 1;          \
        int base = (a);       \
        int exp = (b);        \
        while (exp > 0)       \
        {                     \
            if (exp % 2 == 1) \
                res *= base;  \
            base *= base;     \
            exp /= 2;         \
        }                     \
        res;                  \
    })
 
#ifdef chandan  
#include "starPlatinum.h"
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif
const int mod = 1e9+7;
 
void realmsDomain(){
    ll a,b,c; cin>>a>>b>>c;
    ll gcd = __gcd(a,__gcd(b,c));
    if((a+gcd-1)/(gcd)+(b+gcd-1)/(gcd)+(c+gcd-1)/(gcd)-3<=3){
        cout<<"YES"<<"\n";
    }
    else cout<<"NO"<<"\n";
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