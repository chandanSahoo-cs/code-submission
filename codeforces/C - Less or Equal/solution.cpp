/*It is not the matter of if, it the matter of when*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define all(x) begin(x), end(x)
int main() {
    ll n,k; cin>>n>>k;
    vector<ll>store(n);
    for(auto &ele:store) cin>>ele;
    sort(all(store));
    if(k==store.size()){
        if(store[k-1]!=1e9) cout<<store[k-1]<<"\n";
        else cout<<(ll)1e9<<"\n";
    }
    else if(k==0 && store[k]==1) cout<<-1<<"\n";
    else if(k==0) cout<<1<<"\n";
    else{
        if(store[k-1]!=store[k]){
            if(store[k-1]!=1e9)cout<<store[k-1]<<"\n";
            else cout<<(ll)1e9<<"\n";
        }
        else cout<<-1<<"\n";
    }
}