/*It is not the matter of if, it is the matter of when*/
 
#include <bits/stdc++.h>
using namespace std;
 
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
 
#define ll long long
#define all(x) begin(x), end(x)
 
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
 
#define BIN_EXP(a, b)             \
    ({                            \
        int res = 1;              \
        int base = (a);           \
        int exp = (b);            \
        while (exp > 0)           \
        {                         \
            if (exp % 2 == 1)     \
                res *= base;      \
            base *= base;         \
            exp /= 2;             \
        }                         \
        res;                      \
    })
 
 
void solve()
{
    ll n; cin>>n;
    vector<ll>store(n);
    for(auto &ele:store) cin>>ele;
    ll cnt=1;
    ll ans=0;
    for(ll i=1;i<n;i++){
        // if(store[i]%2==store[i-1]%2){
        //     cnt++;
        // }
        // else{
        //     ans+=cnt;
        //     cnt=0;
        // }
        if(store[i]%2==store[i-1]%2){
            cnt++;
        }
        else{
            ans+=cnt-1;
            cnt=1;
        }
    }
    ans+=cnt-1;
    cout<<ans<<"\n";
}
 
int32_t main()
{
    fastio
 
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
 