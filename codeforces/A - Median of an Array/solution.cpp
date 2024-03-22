#include <bits/stdc++.h>
using namespace std;
//It is not matter of if, it is matter of when
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll int tsts; cin >> tsts; while(tsts--)
int main() {
    fastio
    testcases {
        ll n; cin>>n;
        vector<ll>store(n);
        for(auto &ele:store) cin>>ele;
        sort(store.begin(),store.end());
        ll cnt=1;
        ll temp=store[((n+1)/2)-1]++;
        for(ll i=((n+1)/2);i<n;i++){
            if(store[i]<=temp) cnt++;
        }
        cout<<cnt<<"\n";
    }
    return 0;
}