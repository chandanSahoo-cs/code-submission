/*It is not the matter of if, it the matter of when*/
 
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long
#define ll long long
#define all(x) begin(x), end(x)
 
void solve()
{
    ll n;cin>>n;
    vector<ll>store(n);
    vector<ll>freq(101);
    for(auto &ele:store){
        cin>>ele;
        freq[ele]++;
    }
    cout<<n-*max_element(all(freq))<<"\n";
}
 
int32_t main(){
    fastio
 
    int T=1;
    cin>>T;
 
    while(T--)
        solve();
 
    return 0;
}