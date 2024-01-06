#include <bits/stdc++.h>
using namespace std;
//It is not matter of if, it is matter of when
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll int tsts; cin >> tsts; while(tsts--)
int main() {
    fastio
    testcases {
        ll a,b; cin>>a>>b;
        if((a+b)%2==0) cout<<"Bob"<<"\n";
        else cout<<"Alice"<<"\n";
    }
    return 0;
}