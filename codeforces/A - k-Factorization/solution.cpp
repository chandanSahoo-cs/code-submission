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
    ll n,k; cin>>n>>k;
    vector<ll>store;
    if(k==1){
        store.push_back(n);
    }
    ll div=2;
    while(div<=n && store.size()<k-1 ){
        if(n%div==0){
            store.push_back(div);
            n/=div;
        }
        else{
            div++;
        }
    }
    if(store.size()<k && n!=1) store.push_back(n);
    if(store.size()==k) for(auto ele:store) cout<<ele<<" ";
    else cout<<-1<<" ";
    cout<<"\n";
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