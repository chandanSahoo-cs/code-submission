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
 
    SIEVE(1000)
void solve()
{
    sieveOfEratosthenes();
    ll n,k; cin>>n>>k;
    ll cnt=0;
    ll prev=2;
    for(ll i=3;i<=n;i++){
        if(isPrime[i]){
            if(isPrime[i+prev+1] && i+prev+1<=n){
                cnt++;
            }
            prev=i;
        }
    }
    if(cnt>=k) cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";
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