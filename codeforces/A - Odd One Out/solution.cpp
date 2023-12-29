#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll int tsts; cin >> tsts; while(tsts--)
int main(){
    fastio
    testcases{
        ll a,b,c; cin>>a>>b>>c;
        if(a==b) cout<<c<<endl;
        else if(b==c) cout<<a<<endl;
        else cout<<b<<endl;
    }
    return 0;
}