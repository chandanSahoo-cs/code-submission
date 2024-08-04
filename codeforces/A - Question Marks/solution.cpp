/*It is not the matter of if, it is the matter of when*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll tsts; cin >> tsts; while(tsts--)
#define all(x) begin(x), end(x)
// #define push_back(x) emplace_back(x);
#define push(x) emplace(x);
#define insert(x) emplace(x);
int main() {
    fastio
    testcases {
        ll n; cin>>n;
        string s; cin>>s;
        map<char,ll>mp;
        for(ll i=0;i<4*n;i++){
            mp[s[i]]++;
        }
        ll sum=0;
        for(auto ele:mp){
            if(ele.first!='?') sum+=min(n,ele.second);
        }
        cout<<sum<<"\n";
    }
    return 0;
}