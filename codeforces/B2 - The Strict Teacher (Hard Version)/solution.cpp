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
    ll n,m,q; cin>>n>>m>>q;
    vector<ll>teacher(m);
    for(auto &ele:teacher) cin>>ele;
    sort(all(teacher));
    vector<ll>query(q);
    for(auto &ele:query) cin>>ele;
    for(ll i=0;i<q;i++){
        if(query[i]>teacher[m-1]) cout<< n-teacher[m-1]<<"\n";
        else if(query[i]<teacher[0]) cout<<teacher[0]-1<<"\n";
        else{
            auto ind=lower_bound(all(teacher),query[i]);
            ll rgtTerm=*ind;
            ll lftTerm=*(ind-1);
            ll lft=abs(lftTerm-query[i]);
            ll rgt=abs(rgtTerm-query[i]);
 
            if(lft<rgt){
            ll ans=lft;
            ll carry=(rgt-lft)/2;
            cout<<ans+carry<<"\n";
            }
            else{
            ll ans=rgt;
            ll carry=(lft-rgt)/2;
            cout<<ans+carry<<"\n";
            }
        }
    }
}
 
int32_t main()
{
    fastio int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
 
 
 