#include <bits/stdc++.h>
using namespace std;
//It is not matter of if, it is matter of when
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll int tsts; cin >> tsts; while(tsts--)
int main() {
    fastio
    testcases {
        ll n,m,k; cin>>n>>m>>k;
        vector<ll>lftStr(n);
        vector<ll>rghtStr(m);
        for(auto &ele:lftStr) cin>>ele;
        for(auto &ele:rghtStr) cin>>ele;
        sort(rghtStr.begin(),rghtStr.end());
        sort(lftStr.begin(),lftStr.end());
        ll cnt=0;
        for(ll i=0;i<n;i++){
            for(ll j=0 ;j<m;j++){
                if(lftStr[i]+rghtStr[j]<=k) cnt++;
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}