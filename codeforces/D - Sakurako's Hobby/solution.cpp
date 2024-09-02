#include <bits/stdc++.h>
using namespace std;
 
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
 
#define ll long long
 
void solve()
{
    ll n;
    cin >> n;
    vector<ll> store(n);
    for (auto &ele : store) cin >> ele;
    string s; cin >> s;
    vector<ll> ans(n);
    vector<bool> traversed(n, false);
 
    // for (ll i = 0; i < n; i++)
    // {
    //     if (!visited[i])
    //     {
    //         ll current = i;
    //         vector<ll> cycle_indices;
    //         ll black_count = 0;
 
    //         do
    //         {
    //             visited[current] = true;
    //             cycle_indices.push_back(current);
    //             if (s[current] == '0')
    //                 black_count++;
    //             current = store[current] - 1;
    //         } while (current != i);
 
    //         for (auto idx : cycle_indices)
    //         {
    //             ans[idx] = black_count;
    //         }
    //     }
    // }
 
    for(ll i = 0; i < n; i++){
        if(traversed[i]) continue;
        
        vector<ll> temp;
        temp.push_back(i);
        traversed[i] = true;
        ll cnt = (s[i] == '0') ? 1 : 0;
        ll current = store[i] - 1;
        while(current != i){
            if(s[current] == '0') cnt++;
            temp.push_back(current);
            traversed[current] = true;
            current = store[current] - 1;
        }
        
        for(auto idx : temp){
            ans[idx] = cnt;
        }
    }
 
    for (auto val : ans)
    {
        cout << val << " ";
    }
    cout << "\n";
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