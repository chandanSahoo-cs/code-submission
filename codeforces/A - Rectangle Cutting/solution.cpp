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
        if( (a%2!=0 && b%2!=0)){
            cout<<"NO"<<"\n";
            continue;
        }
        bool flag=false;
        if((a/2!=b && a%2==0) || (b/2!=a && b%2==0)) flag=true;
        if(flag) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
    return 0;
}