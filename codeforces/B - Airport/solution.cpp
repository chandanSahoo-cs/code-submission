#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define all(x) begin(x), end(x)
 
int main() {
    fastio
    ll n,m; cin>>n>>m;
    vector<ll>store(m);
    for(auto &ele:store) cin>>ele;
    vector<ll>maxStr=store;
    sort(all(maxStr),greater<int>());
    ll mx=0;
    ll n1=n;
    while(n1>0){
        mx+=maxStr[0];
        if(maxStr[0]!=0){
            maxStr[0]--;
        }
        sort(all(maxStr),greater<int>());
        n1--;
    }
    vector<ll>mnStr=store;
    sort(all(mnStr));
    ll mn=0;
    ll n2=n;
    while(n2>0){
        for(ll i=0;i<m;i++){
            if(mnStr[i]>0){
                mn+=mnStr[i];
                mnStr[i]--;
                break;
            }
        }
        sort(all(mnStr));
        n2--;
    }
    cout<<mx<<" "<<mn<<"\n";
}