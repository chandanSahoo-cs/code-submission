#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
#define velociraptor ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);                                             
#define all(v) v.begin(),v.end()
#define lcd(a,b) a*(b/__gcd(a,b))
 
#define ll long long
 
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
 
#ifdef chandan  
#include "starPlatinum.h"
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif
const int mod = 1e9+7;
 
void realmsDomain(){
    ll n; cin>>n;
    vector<ll>store(n-1);
    for(auto &ele:store) cin>>ele;
    vector<ll>ans;
    bool ascend=false, descend=false;
    bool push = 0;
    for(ll i=0;i<n-2;i++){
        if(!ascend && !descend){
            if(store[i]<store[i+1]){
                ascend=true;
                ans.push_back(store[i]);
                ans.push_back(0);
            }
            else{
                descend=true;
                ans.push_back(store[i]);
            } 
        }
        else if(descend && store[i]<store[i+1] ){
            ascend=true;
            descend=false;
            push=true;
            ans.push_back(store[i]);
            ans.push_back(0);
        }
        else if(ascend && store[i]>store[i+1]){
            ans.push_back(store[i+1]);
        }
        else{
            ans.push_back(store[i]);
        }
    }
    if(n==2){
        ans.push_back(store[0]);
        ans.push_back(0);
    }
    else ans.push_back(store.back());
    if(descend && !push) ans.push_back(0);
    for(auto &ele:ans) cout<<ele<<" ";
    cout<<"\n";
}
 
 
 
 
int main() {
clock_t time_req = clock();
velociraptor
 
 
#ifdef chandan 
freopen("error.txt", "w", stderr); 
#endif
 
ll tsts = 1 ; 
 
cin>>tsts;    
for(ll testcase = 1 ; testcase <=  tsts ; testcase++ ){
    realmsDomain();
}
 
 
 
 
#ifdef chandan
    cerr << "Time : " << fixed << setprecision(6) << ((double)(clock() - time_req)) / CLOCKS_PER_SEC << endl;
#endif
 
    return 0;
}