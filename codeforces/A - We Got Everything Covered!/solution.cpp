#include <bits/stdc++.h>
using namespace std;
//It is not matter of if, it is matter of when
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll int tsts; cin >> tsts; while(tsts--)
int main() {
    fastio
    testcases {
        ll n,k; cin>>n>>k;
        string sTUs ="a";
        for(int i=1;i<k;i++){
            sTUs+=char(97+i);
        }
        string ans;
        for(int i=0;i<n;i++){
            ans+=(sTUs);
        }
        cout<<ans<<"\n";
    }
    return 0;
}