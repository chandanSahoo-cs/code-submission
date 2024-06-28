#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define all(x) begin(x), end(x)
 
int main() {
    fastio
    ll n; cin>>n;
    for(ll i=0;i<n;i++){
        ll x,y; cin>>x>>y;
        cout<<(y>=-1?"YES":"NO")<<"\n";
    }
}