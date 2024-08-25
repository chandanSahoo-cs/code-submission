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
    string s; cin>>s;
    string s1 = "" + string(1, s[2]) + s[1] + s[0];
    string s2 = "" + string(1, s[0]) + s[2] + s[1];
    string s3 = "" + string(1, s[1]) + s[0] + s[2];
    if(s1=="abc" || s2=="abc" || s3=="abc" || s=="abc") cout<<"YES"<<"\n";
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