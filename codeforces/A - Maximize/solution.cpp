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
        ll x; cin>>x;
        ll mx=-1;
        ll ans=-1;
        for(ll i=x-1;i>=1;i--){
            if(mx<__gcd(x,i)+i){
                mx=max(__gcd(x,i)+i,mx);
                ans=i;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}