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
        vector<ll>store(n);
        for(auto &ele:store) cin>>ele;
        bool flag=true;
        bool ansflag=true;
        for(ll i=0;i<n-1;i++){
            if(store[i]>store[i+1] && flag) flag=false;
            else if(store[i]>store[i+1] && !flag){
                ansflag=false;
            }
        }
        if(store[n-1]>store[0] && !flag) ansflag=false;
        if(ansflag) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
    return 0;
}