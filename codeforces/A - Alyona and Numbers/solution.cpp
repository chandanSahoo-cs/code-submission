/*It is not the matter of if, it the matter of when*/
 
#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define int long long
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
 
    SIEVE(1000)
void solve()
{
    ll n,m; cin>>n>>m;
    map<ll,ll>mpN;
    map<ll,ll>mpM;
    for(ll i=1;i<=n;i++){
        mpN[i%5]++;
    }
    for(ll i=1;i<=m;i++){
        mpM[i%5]++;
    }
    ll ans=mpN[0]*mpM[0];
    for(ll i=1;i<5;i++){
        ans+=mpN[i]*mpM[5-i];
    }
    cout<<ans<<"\n";
}
 
int32_t main()
{
    fastio
 
        int T = 1;
    // cin >> T;
 
    while (T--)
        solve();
 
    return 0;
}