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
        string s; cin>>s;
        bool flag01=true;
        ll cnt=1;
        for(ll i=0;i<s.size()-1;i++){
            if(s[i]!=s[i+1]){
                if(s[i]=='0' && flag01){
                    flag01=false;
                }
                else cnt++;
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}