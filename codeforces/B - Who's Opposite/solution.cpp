/*It is not the matter of if, it is the matter of when*/
 
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
    ll a,b,c; cin>>a>>b>>c;
    if(c<=2*abs(a-b) && a<=2*abs(a-b) && b<=2*abs(a-b)){
        if(c-abs(a-b)>0) cout<<c-abs(a-b)<<"\n";
        else if(c+abs(a-b)<=2*abs(a-b) && c+abs(a-b)!=a && c+abs(a-b)!=b) cout<<c+abs(a-b)<<"\n";
    }
    else cout<<-1<<"\n";
}
 
int32_t main()
{
    fastio
    int T=1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}