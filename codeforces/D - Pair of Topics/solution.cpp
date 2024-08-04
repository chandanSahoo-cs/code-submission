/*It is not the matter of if, it is the matter of when*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll tsts; cin >> tsts; while(tsts--)
#define all(x) begin(x), end(x)
int main() {
    fastio
    ll n;cin>>n;
    vector<ll>a(n);
    vector<ll>b(n);
    for(auto &ele:a)cin>>ele;
    for(auto &ele:b)cin>>ele;
    vector<ll>c;
    for(ll i=0;i<n;i++){
        c.push_back(a[i]-b[i]);
    }
    ll cnt=0;
    sort(all(c));
    for(ll i=0;i<n;i++){
        ll target;
        if(c[i]<=0){
            target=abs(c[i])+1;
            ll it=lower_bound(c.begin()+i+1,c.end(),target) - c.begin();
            cnt+=n-it;
        }
        else cnt+=n-i-1;
    }
    cout<<cnt<<"\n";
}