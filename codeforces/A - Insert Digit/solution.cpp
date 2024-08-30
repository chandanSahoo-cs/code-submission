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
    ll n, k;
    cin >> n >> k;
    string s;
    cin>>s;
    bool flag = false;
    string ans;
    
    for (ll i = 0; i < n; i++) {
        if (s[i] - '0' < k) {
            ans = s.substr(0, i) + to_string(k) + s.substr(i, n - i);
            flag = true;
            break;
        }
    }
    
    // If no smaller digit was found, append `k` to the end
    if (!flag) {
        ans = s + to_string(k);
    }
    
    cout << ans << "\n";
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
 