#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll tsts; cin >> tsts; while(tsts--)
#define all(x) begin(x), end(x)
int main() {
    fastio
    testcases {
        ll x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        if(y1>x1){
            if(x2>=y1 && x2>y2) cout<<"NO"<<"\n";
            else cout<<"YES"<<"\n";
        }
        else if(y1<x1){
            if(y2>=x1 && y2>x2) cout<<"NO"<<"\n";
            else cout<<"YES"<<"\n";
        }
    }
    return 0;
}