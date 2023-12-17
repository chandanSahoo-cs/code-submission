#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll int tsts; cin >> tsts; while(tsts--)
int main(){
    fastio
    testcases{
        ll n,m;
        cin>>n>>m;
        ll mx=max(n,m);
        cout<<mx<<endl;
    }
    return 0;
}