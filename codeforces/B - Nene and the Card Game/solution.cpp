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
        vector<ll>freq(n+1,0);
        for(ll i=0;i<n;i++){
            cin>>store[i];
            freq[store[i]]++;
        }
        ll cnt=0;
        for(ll i=1;i<n+1;i++){
            if(freq[i]==2) cnt++;
        }
        cout<<cnt<<"\n";
    }
    return 0;
}