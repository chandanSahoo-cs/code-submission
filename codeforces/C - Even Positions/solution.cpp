/*It is not the matter of if, it is the matter of when*/
/**/
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
        ll cnt=0;
        bool flagLeft=false;
        bool flagRight=false;
        for(ll i=n-1;i>=0;i--){
            if(s[i]==')') cnt++;
            else if(s[i]=='('){
                cnt--;
                cnt+=4;
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}