//**It is not matter of if, it is matter of when
// #include <chandan/skills.h>
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll int tsts; cin >> tsts; while(tsts--)
int main() {
    fastio
    testcases {
        ll n; cin>>n;
        vector<ll>store(n);
        for(auto &ele:store) cin>>ele;
        ll ans=LLONG_MIN;
        if(n==2){
            cout<<min(store[0],store[1])<<"\n";
            continue;
        }
        for(ll i=0;i<n-2;i++){
            vector<ll>temp={store[i],store[i+1],store[i+2]};
            sort(temp.begin(),temp.end());
            ans=max(temp[1],ans);
        }
        cout<<ans<<"\n";
    }
    return 0;
}