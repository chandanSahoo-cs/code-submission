#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll tsts; cin >> tsts; while(tsts--)
#define all(x) begin(x), end(x)
int main() {
    fastio
    testcases {
        ll n,m; cin>>n>>m;
        string s; cin>>s;
        vector<ll>store(m);
        for(auto &ele:store) cin>>ele;
        string c; cin>>c;
        sort(all(c));
        vector<ll>freq(n,0);
        for(ll i=0;i<m;i++){
            freq[store[i]-1]=1;
        }
        ll j=0;
        for(ll i=0;i<n;i++){
            if(freq[i]==1){
                s[i]=c[j];
                j++;
            }
        }
        cout<<s<<"\n";
    }
    return 0;
}