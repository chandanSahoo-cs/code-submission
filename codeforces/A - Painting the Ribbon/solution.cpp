//**It is not matter of if, it is matter of when**
// #include <chandan/skills.h>
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll int tsts; cin >> tsts; while(tsts--)
int main() {
    fastio
    testcases {
        ll n,m,k; cin>>n>>m>>k;
        if(n-(n+(m-1))/m<=k) cout<<"NO"<<"\n";
        else cout<<"YES"<<"\n";
    }
    return 0;
}