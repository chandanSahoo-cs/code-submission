#include <bits/stdc++.h>
using namespace std;
//It is not matter of if, it is matter of when
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll int tsts; cin >> tsts; while(tsts--)
int main() {
    fastio
    testcases {
        string s; cin>>s;
        ll cntA=0, cntB=0;
        for(ll i=0;i<5;i++){
            if(s[i]=='A') cntA++;
            else cntB++;
        }
        if(cntA>cntB) cout<<'A'<<"\n";
        else cout<<'B'<<"\n";
    }
    return 0;
}