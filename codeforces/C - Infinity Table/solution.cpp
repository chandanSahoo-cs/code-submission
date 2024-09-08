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
    ll n; cin>>n;
    ll trg=sqrt(n);
    if(BIN_EXP(trg,2)==n){
        cout<<trg<<" "<<1<<"\n";
    }
    else{
        ll x=trg+1,y=trg+1;
        ll gap=(BIN_EXP(trg+1,2)-BIN_EXP(trg,2)+1)/2;
        if(n>=BIN_EXP(trg,2)+gap){
            y-=n-(BIN_EXP(trg,2)+gap);
        }
        else{
            x-=BIN_EXP(trg,2)+gap-n;
        }
        cout<<x<<" "<<y<<"\n";
    }
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