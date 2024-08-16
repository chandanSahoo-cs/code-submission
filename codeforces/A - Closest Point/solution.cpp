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
        vector<ll>store(n);
        for(auto &ele:store) cin>>ele;
        if(n>2) cout<<"NO"<<"\n";
        else{
            if(abs(store[0]-store[1])<=1){
                cout<<"NO"<<"\n";
            }
            else cout<<"YES"<<"\n";
        }
    }
    return 0;
}