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
        string s; cin>>s;
        string temp="";
        for(ll i=s.size()-1;i>=0;i--){
            temp+=s[i];
        }
        if(s<=temp) cout<<s<<"\n";
        else cout<<temp+s<<"\n";
    }
    return 0;
}