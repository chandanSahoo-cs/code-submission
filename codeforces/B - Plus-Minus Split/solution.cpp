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
        string s; cin>>s;
        ll ngCnt=0;
        for( ll i=0;i<n;i++){
            if(s[i]=='-') ngCnt++;
        }
        if(ngCnt==n) cout<<n<<"\n";
        else cout<<abs(n-(2*ngCnt))<<"\n";
    }
    return 0;
}