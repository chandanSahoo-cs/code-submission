/*It is not the matter of if, it the matter of when*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define all(x) begin(x), end(x)
const ll INF=1e18;
int main() {
    fastio
    ll n,m; cin>>n>>m;
    vector<ll>a(n),b(n);
    for(auto &ele:a) cin>>ele;
    for(auto &ele:b) cin>>ele;
    set<ll>ans;
    ll temp=a[0];
    for(ll i=0;i<n;i++){
        if(temp>b[i]){
            ans.insert(m-temp+b[i]);
        }
        else{
            ans.insert(b[i]-temp);
        }
    }
    ll x=INF;
    vector<ll>temp2;
    sort(all(b));
    for(auto &ele:ans){
        for(ll i=0;i<n;i++){
            temp2.push_back((a[i]+ele)%m);
        }
        sort(all(temp2));
        if(temp2==b){
            cout<<ele<<"\n";
            break;
        }
        temp2.clear();
    }
}