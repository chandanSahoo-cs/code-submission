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
    ll l, r;
    cin >> l >> r;
    if (l * 2 <= r)
    {
        cout << l << " " << l * 2 << "\n";
    }
    else
        cout << -1 << " " << -1 << "\n";
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