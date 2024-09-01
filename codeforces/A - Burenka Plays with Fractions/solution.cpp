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
 
 
void solve(ll T)
{
    ll a,b,c,d; cin>>a>>b>>c>>d;
    ll gcd1=__gcd(a,b);
    ll gcd2=__gcd(c,d);
    a/=gcd1,b/=gcd1,c/=gcd2,d/=gcd2;
 
    // cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
    if(a*d==c*b ) cout<<0<<"\n";
    else{
        if(a*d==0 || b*c==0) cout<<1<<"\n";
        else if(max((a*d),(c*b))%min((a*d),(c*b))==0) cout<<1<<"\n";
        else cout<<2<<"\n";
    }
}
 
 
int32_t main()
{
    fastio
    int T;
    cin >> T;
    ll i=1;
    while (T--)
        solve(i++);
    return 0;
}
 