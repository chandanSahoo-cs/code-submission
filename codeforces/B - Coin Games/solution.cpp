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
        ll cntU=0,cntD=0;
        for(ll i=0;i<n;i++){
            if(s[i]=='U') cntU++;
            else cntD++;
        }
        // if(n%2==0){
        //     if(cntU<cntD) cout<<"YES"<<"\n";
        //     else cout<<"NO"<<"\n";
        // }
        // else{
        //     if(cntU<cntD) cout<<"NO"<<"\n";
        //     else cout<<"YES"<<"\n";
        // }
        if(cntU%2!=0) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
    return 0;
}