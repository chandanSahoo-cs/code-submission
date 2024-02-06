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
        vector<pair<ll,ll>>ab(n);
        for(auto &ele:ab){
            cin>>ele.first;
        }
        for(auto &ele:ab){
            cin>>ele.second;
        }
        sort(ab.begin(),ab.end());
        for(auto ele:ab){
            cout<<ele.first<<" ";
        }
        cout<<"\n";
        for(auto ele:ab){
            cout<<ele.second<<" ";
        }
        cout<<"\n";
    }
    return 0;
}