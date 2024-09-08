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
    string s; cin>>s;
    ll l=s.size();
    ll cntOg=0,cntTemp=0;
    bool flagR=true,flagG=false;
    map<char,ll>mp;
    for(ll i=0;i<l;i++){
        mp[s[i]]++;
    }
    for(auto ele:mp){
        if(ele.second>1) cntOg++;
        else{
            cntTemp++;
        }
        if(cntTemp==2){
            cntOg++;
            cntTemp=0;
        }
    }
    cout<<cntOg<<"\n";
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