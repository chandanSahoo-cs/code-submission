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
        string s=to_string(n);
        ll l=s.size();
        if(s[0]=='1' &&  s[1]=='0'){
            if(s[2]!='1' && s[2]!='0' && s.size()>2){
                cout<<"YES"<<"\n";
            }
            else if(s[2]=='1' && s.size()>3) cout<<"YES"<<"\n";
            else cout<<"NO"<<"\n";
        }
        else cout<<"NO"<<"\n";
    }
    return 0;
}