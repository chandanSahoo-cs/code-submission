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
    ll n,k; cin>>n>>k;
    if(n-k!=1) cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";
}
 
int32_t main()
{
    fastio
 
        int T = 1;
    cin >> T;
 
    while (T--)
        solve();
 
    return 0;
}