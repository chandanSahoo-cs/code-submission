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
        ll n; cin>>n;
        string s; cin>>s;
        set<char>r;
        for(ll i=0;i<n;i++){
            r.insert(s[i]);
        }
        vector<char>nR(r.begin(),r.end());
        map<char,char>alpha;
        for(ll i=0;i<r.size();i++){
            alpha[nR[i]]=nR[nR.size()-1-i];
        }
        string ans="";
        for(ll i=0;i<n;i++){
            ans+=alpha[s[i]];
        }
        cout<<ans<<"\n";
    }
    return 0;
}