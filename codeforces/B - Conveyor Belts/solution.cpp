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
 
ll getRing(ll n, ll x,ll y){
    return min({x,y,n-x+1,n-y+1});
}
 
void solve()
{
    ll n,x1,y1,x2,y2; cin>>n>>x1>>y1>>x2>>y2;
    // cout<<getRing(n,x1,y1)<<"\n";
    // cout<<getRing(n,x2,y2)<<"\n";
    cout<<abs(getRing(n,x1,y1)-getRing(n,x2,y2))<<"\n";
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
 