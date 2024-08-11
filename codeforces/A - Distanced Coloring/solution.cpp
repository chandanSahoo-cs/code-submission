#include<bits/stdc++.h>
using namespace std;
 
#define ll           long long
#define all(x)       x.begin(), x.end()
#define pb           push_back
 
#ifdef NISHPC
#include "chandan.h"
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif
 
 
template<class T>void output (vector<T> &a) {for (auto &x : a) {cout << x << ' ';}cout << '\n';}
template<typename T, typename TT> void chmin (T &a, TT b) {if (a > b) swap(a, b);}
template<typename T, typename TT> void chmax (T &a, TT b) {if (a < b) swap(a, b);}
 
 
 
void solve() {
    ll n,m,k; cin>>n>>m>>k;
    ll ans=1;
    if(n/k==0) ans*=n;
    else ans*=k;
 
    if(m/k==0) ans*=m;
    else ans*=k;
    cout<<ans<<"\n";
} 
 
 
int32_t main() {    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    #ifdef NISHPC
    freopen("error.txt", "w", stderr);
    #endif
 
 
    int tc = 1;
    cin >> tc;
 
    for (int cases = 1; cases <= tc; ++cases) {
       solve();
       // cout << (solve() ? "YES\n" : "NO\n");
       // cout << "Case # " << cases;
   } 
 
    #ifdef NISHPC
   double timeTaken = 1000.0 * clock() / CLOCKS_PER_SEC;
   cout << "\n[Finished in " << timeTaken << "ms]";
   cerr << "\n[Finished in " << timeTaken << "ms]";
    #endif
 
   return 0;
}