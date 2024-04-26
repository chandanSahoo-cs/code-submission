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
        ll lastIndex=n-1;
        ll cnt=0;
        ll moves=0;
        ll temp;
        for(ll i=n-1;i>=0;i--){
            if(s[i]=='0'){
                moves+=(lastIndex-i);
                cout<<moves<<" ";
                cnt++;
                lastIndex--;
            }
        }
        for(ll i=0;i<n-cnt;i++){
            cout<<"-1"<<" ";
        }
        cout<<"\n";
    }
    return 0;
}