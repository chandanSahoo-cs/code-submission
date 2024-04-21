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
        vector<ll>freq(100+1,0);
        ll cnt=0;
        for(ll i=0;i<n;i++){
            freq[store[i]]++;
        }
        for(ll i=0;i<101;i++){
            cnt+=(freq[i])/3;
        }
        cout<<cnt<<"\n";
    }
    return 0;
}