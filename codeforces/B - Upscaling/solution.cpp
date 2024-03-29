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
        bool row=true;
        for(ll i=1;i<=2*n;i++){
            bool col=true;
            for(ll j=1;j<=2*n;j++){
                if( row==col) cout<<"#";
                else cout<<".";
                if(j%2==0) col=!col;
            }
            if(i%2==0) row=!row;
            cout<<"\n";
        }
    }
    return 0;
}