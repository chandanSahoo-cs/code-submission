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
    ll n; cin>>n;
    string s; cin>>s;
    ll sq=sqrt(n);
    ll temp=sq*sq;
    if(BIN_EXP(sq,2)==n){
        ll lft=0,mid=0,rgt=0;
        ll sum=0;
        for(ll i=0;i<n;i++){
            sum+=s[i]-'0';
        }
        if(sum==(sq*2)+(sq-2)*2) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
    else cout<<"NO"<<"\n";
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
 