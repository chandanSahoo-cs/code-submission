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
        ll sm=log2(n);
        ll ans=1;
        while(sm>0){
            ans*=2;
            sm--;
        }
        cout<<ans<<"\n";
    }
    return 0;
}