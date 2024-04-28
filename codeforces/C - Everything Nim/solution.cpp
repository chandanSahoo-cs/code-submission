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
        sort(store.begin(),store.end());
        ll sub=0;
        bool ans=false;
        for(ll i=0;i<n;i++){
            if(store[i]-sub==1){
                ans=!ans;
                sub++;
            }
            else if(store[i]-sub>1){
                ans=!ans;
                break;
            }
        }
        if(ans) cout<<"Alice"<<"\n";
        else cout<<"Bob"<<"\n";
    }
    return 0;
}