#include <bits/stdc++.h>
using namespace std;
//It is not matter of if, it is matter of when
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll int tsts; cin >> tsts; while(tsts--)
int main() {
    fastio
    testcases {
        string s;cin>>s;
        string ans;
        string s1=s.substr(0,2);
        int val=stoi(s1);
        // cout<<s1<<" "<<stoi(s1)<<"\n";
        if(val==0){
            ans="12:"+s.substr(3,5)+" "+"AM";
        }
        else if(val<12){
            ans=s+" "+"AM";
        }
        else if(val==12){
            ans=s+" "+"PM";
        }
        else {
            if(val-12<10) ans="0"+to_string(val-12)+":"+s.substr(3,5)+" "+"PM";
            else ans=to_string(val-12)+":"+s.substr(3,5)+" "+"PM";
        }
        cout<<ans<<"\n";
    }
    return 0;
}