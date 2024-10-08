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
 
long long BIN_EXP(ll a,ll b)
{
    if (b == 0)
        return 1;
 
    ll p = BIN_EXP(a, b / 2);
    p *= p;
 
    if (b % 2)
        p *= a;
 
    return p;
}
void realmsDomain(){
    ll n,k; cin>>n>>k;
    ll temp=n;
    ll cnt=0;
    if(k==1 || k>n){
        cout<<n<<"\n";
        return;
    }
    while(temp>0){
        ll sub=0;
        while(BIN_EXP(k,sub)<=temp) sub++;
        temp-=BIN_EXP(k,sub-1);
        cnt++;
        if(temp<k){
            cout<<cnt+temp<<"\n";
            return;
        }
    }
    cout<<cnt<<"\n";
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