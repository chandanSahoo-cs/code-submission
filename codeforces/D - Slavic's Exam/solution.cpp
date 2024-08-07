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
        string t; cin>>t;
        ll slen=0,tlen=0;
        while(slen<s.size() && tlen<t.size()){
            if(t[tlen]==s[slen]){
                tlen++;
            }
            else if(s[slen]=='?'){
                s[slen]=t[tlen];
                tlen++;
            }
            slen++;
        }
        for(ll i=0;i<s.size();i++){
            if(s[i]=='?') s[i]='a';
        }
        if(tlen==t.size()){
            cout<<"YES"<<"\n";
            cout<<s<<"\n";
        }
        else cout<<"NO"<<"\n";
    }
    return 0;
}