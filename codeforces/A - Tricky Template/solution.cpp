#include <bits/stdc++.h>
using namespace std;
//It is not matter of if, it is matter of when
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll int tsts; cin >> tsts; while(tsts--)
int main() {
    fastio
    testcases {
        ll n; cin>>n; string a,b,c; cin>>a>>b>>c;
        bool flag=false;
        for(ll i=0;i<n;i++){
            if(a[i]!=c[i] && b[i]!=c[i]){
                flag=true;
                break;
            }
        }
        if(flag) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
    return 0;
}