#include <bits/stdc++.h>
using namespace std;
// It is not matter of if, it is matter of when
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ll long long
#define testcases \
    ll int tsts;  \
    cin >> tsts;  \
    while (tsts--)
int main()
{
    fastio
        testcases
    {
        ll n;
        cin >> n;
        ll val = 2;
        vector<ll> store;
        for (ll i = 26; i >= 1; i--)
        {
            if (i <= n - val)
            {
                store.push_back(i);
                n -= i;
                val--;
                break;
            }
        }
        for (ll i = 26; i >= 1; i--)
        {
            if (i <= n - val)
            {
                store.push_back(i);
                n -= i;
                val--;
                break;
            }
        }
        for (ll i = 26; i >= 1; i--)
        {
            if (i <= n - val)
            {
                store.push_back(i);
                n -= i;
                val--;
                break;
            }
        }
        string s;
        for (ll i = 2; i >= 0; i--)
        {
            s += static_cast<char>('a' + store[i]-1);
        }
        cout << s << "\n";
    }
    return 0;
}