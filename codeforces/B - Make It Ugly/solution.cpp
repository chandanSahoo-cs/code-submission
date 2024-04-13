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
        // vector<ll>ans(n,-1);
        ll check=INT_MAX;
        ll prev=-1;
        bool flag=false;
        for(ll i=0;i<n;i++){
            if(store[i]!=store[0]){
                check=min(check,i-prev-1);
                prev=i;
                flag=true;
            }
        }
        check=min(check,n-prev-1);
        if(flag) cout<<check<<"\n";
        else cout<<-1<<"\n";
    }
    return 0;
}