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
 
#define BIN_EXP(a, b)         \
    ({                        \
        int res = 1;          \
        int base = (a);       \
        int exp = (b);        \
        while (exp > 0)       \
        {                     \
            if (exp % 2 == 1) \
                res *= base;  \
            base *= base;     \
            exp /= 2;         \
        }                     \
        res;                  \
    })
 
 
void solve()
{
    ll n; cin>>n;
    string ans="";
    string t="aeiou";
    ll temp=n/5;
    ll carry=n%5;
 
    // while(n>5){
    //     ans+='a';
    //     n--;
    // }
    // for(ll i=0;i<n;i++){
    //     ans+=t[i];
    // }
    for(ll i=0;i<5;i++){
        for(ll j=0;j<temp;j++){
            ans+=t[i];
        }
        if(carry) ans+=t[i],carry--;
    }
    cout<<ans<<"\n";
}
 
int32_t main()
{
    fastio int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}