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
        ll n,k; cin>>n>>k;
        if(n==1) cout<<k;
        else{
            ll p=log2(k);
            cout<<(ll)pow(2,p)-1<<" ";
            cout<<k-(ll)(pow(2,p)-1)<<" ";
            for(ll i=0;i<n-2;i++){
                cout<<0<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}