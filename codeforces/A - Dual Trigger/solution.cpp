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
        ll cnt=0;
        bool flag=false;
        for(ll i=0;i<n;i++){
            if(s[i]=='1'){
                cnt++;
                if(s[i-1]=='1') flag=true;
            }
        }
        if(cnt%2==0 && cnt!=2) cout<<"YES"<<"\n";
        else if(cnt==2 && !flag) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
    return 0;
}