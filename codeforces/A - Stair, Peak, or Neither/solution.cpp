#include <bits/stdc++.h>
using namespace std;
//It is not matter of if, it is matter of when
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll int tsts; cin >> tsts; while(tsts--)
int main() {
    fastio
    testcases {
        ll a,b,c; cin>>a>>b>>c;
        if(a<b){
            if(b<c) cout<<"STAIR"<<"\n";
            else if(b>c) cout<<"PEAK"<<"\n";
            else cout<<"NONE"<<"\n";
        }
        else cout<<"NONE"<<"\n";
    }
    return 0;
}