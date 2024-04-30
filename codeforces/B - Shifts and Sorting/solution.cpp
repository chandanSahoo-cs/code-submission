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
        string s;
        cin>>s;
        ll cnt1=0;
        ll cnt=0;
        bool flag=false;
        for(ll i=0;i<s.size();i++){
            if(s[i]=='1') cnt1++;
            if(s[i]=='0') cnt+=(cnt1)+(cnt1==0?0:1);
        }
        cout<<cnt<<"\n";
    }
    return 0;
}