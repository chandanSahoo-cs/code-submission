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
    vector<vector<ll>>store(n,vector<ll>(n-1));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n-1;j++){
            cin>>store[i][j];
        }
    }
    vector<map<ll,ll>>freq(n-1);
    for(ll i=0;i<n-1;i++){
        for(ll j=0;j<n;j++){
            freq[i][store[j][i]]++;
        }
    }
    // for(ll i=0;i<n-1;i++){
    //     cout<<i<<":"<<"\n";
    //     for(auto ele:freq[i]){
    //         cout<<ele.first<<":"<<ele.second<<"\n";
    //     }
    // }
    vector<ll>ans;
    ll prev;
    for(ll i=0;i<n-1;i++){
        ll mxFreq=0,mxEle=0;
        for(auto ele:freq[i]){
            if(ele.second>=mxFreq){
                prev=mxEle;
                mxFreq=ele.second;
                mxEle=ele.first;
            }
            else{
                prev=ele.first;
            }
        }
        if(i!=0){
            if(freq[i-1][mxEle]!=0){
                ans.push_back(mxEle);
            }
            else ans.push_back(prev);
        }
        else{
            ans.push_back(mxEle);
        }
    }
    ll sum=0;
    for(auto ele:ans) sum+=ele,cout<<ele<<" ";
    cout<<(n*(n+1))/2-sum;
    cout<<"\n";
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
 