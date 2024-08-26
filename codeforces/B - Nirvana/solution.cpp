/*It is not the matter of if, it the matter of when*/
 
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
        ll res = 1;              \
        ll base = (a);           \
        ll exp = (b);            \
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
    string s = to_string(n);
    ll l=s.size();
    ll mx=(s[0]-'0');
    ll ans=1;
    for(ll i=0;i<l;i++){
        ll temp=ans;
        temp*=((s[i]-'0')-1!=0?(s[i]-'0')-1:1);
        for(ll j=0;j<l-(i+1);j++){
            temp*=9;
        }
        mx=max(temp,mx);
        ans*=(s[i]-'0');
    }
    ll prod=1;
    while(n>0){
        prod*=n%10;
        n/=10;
    }
    cout<<max(mx,prod)<<"\n";
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