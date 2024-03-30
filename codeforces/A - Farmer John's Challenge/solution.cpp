#include <bits/stdc++.h>
using namespace std;
//It is not matter of if, it is matter of when
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll int tsts; cin >> tsts; while(tsts--)
int main() {
    fastio
    testcases {
        ll n,k; cin>>n>>k;
        if(n==k){
            for(ll i=0;i<n;i++) cout<<1<<" ";
        }
        else if(k==1){
            for(ll i=1;i<=n;i++) cout<<i<<" ";
        }
        else cout<<-1<<" ";
        cout<<"\n";
    }
    return 0;
}