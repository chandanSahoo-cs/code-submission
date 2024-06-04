#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll tsts; cin >> tsts; while(tsts--)
#define all(x) begin(x), end(x)
 
int main() {
    fastio
    testcases {
        ll n;
        cin >> n;
        vector<ll> a(n), b(n);
        for (auto &ele : a) cin >> ele;
        for (auto &ele : b) cin >> ele;
        
        ll m;
        cin >> m;
        vector<ll> d(m);
        for (auto &ele : d) cin >> ele;
 
        map<ll, ll> freqd;
        for (ll i = 0; i < m; i++) {
            freqd[d[i]]++;
        }
 
        bool flag1 = true;
        for (ll i = 0; i < n; i++) {
            if (b[i] == a[i]) {
                continue;
            } else if (freqd[b[i]] > 0) {
                freqd[b[i]]--;
            } else {
                flag1 = false;
                break;
            }
        }
 
        bool flag2 = false;
        for (ll i = 0; i < n; i++) {
            if (b[i] == d[m - 1]) {
                flag2 = true;
                break;
            }
        }
 
        if (flag1 && flag2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}