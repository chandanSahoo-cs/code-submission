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
        cout<<abs(store[0]-store[n-1])+abs(store[n-1]-store[1])+abs(store[1]-store[n-2])+abs(store[n-2]-store[0])<<"\n";
    }
    return 0;
}