//**It is not matter of if, it is matter of when**
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
        bool flag=false;
        for(ll i=0;i<n;i++){
            if(i==store[store[i]-1]-1) flag=true;
        }
        if(flag) cout<<2<<"\n";
        else cout<<3<<"\n";
    }
    return 0;
}