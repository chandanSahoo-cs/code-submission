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
        string s; cin>>s;
        if(s.size()==1) {
            s=s.substr(0,s.size())+(s[0]!='b'?'b':'a');
            cout<<s<<"\n";
            continue;
        }
        else{
            bool flag=false;
            for(ll i=1;i<s.size();i++){
            if(s[i-1]==s[i]){
                s=s.substr(0,i)+(s[i-1]!='b'?'b':'a')+s.substr(i,s.size());
                flag=true;
                break;
            }
        }
        if(flag) cout<<s<<"\n";
        else{
            s=s.substr(0,s.size())+(s[s.size()-1]!='b'?'b':'a');
            cout<<s<<"\n";
        }
        }
        
    }
    return 0;
}