#include "bits/stdc++.h"
using namespace std;
 
#define velociraptor ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);                                             
#define all(v) v.begin(),v.end()
#define lcd(a,b) a*(b/__gcd(a,b))
#define ll long long
 
const int mod = 1e9+7;
 
#ifdef chandan  
#include "starPlatinum.h"
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif
 
void realmsDomain() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &ele : a) cin >> ele;
 
    map<ll, ll> mp; 
    for (ll i = 0; i < n; i++) {
        if (mp.find(a[i]) == mp.end()) {
            mp[a[i]] = i ;
        } else {
            mp[a[i]] = min(mp[a[i]], i);
        }
    }
    sort(a.begin(), a.end(), greater<ll>());
 
    map<ll, ll> greater;
    ll temp = 0;
    for (ll i = 0; i < n; i++) {
        if (greater.find(a[i]) == greater.end()) {
            greater[a[i]] = temp;
        }
        temp++;
    }
 
    ll ans = LLONG_MAX;
    for (auto ele : mp) {
        ll value = ele.first;
        ans = min(ans, ele.second + greater[value]);
    }
 
    cout << ans<< "\n";
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