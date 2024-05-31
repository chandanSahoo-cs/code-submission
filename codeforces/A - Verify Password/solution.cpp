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
        bool flag=false;
        for(ll i=1;i<n;i++){
            if(s[i]<s[i-1]){
                flag=true;
                break;
            }
        }
        if(flag) cout<<"NO"<<"\n";
        else cout<<"YES"<<"\n";
    }
    return 0;
}