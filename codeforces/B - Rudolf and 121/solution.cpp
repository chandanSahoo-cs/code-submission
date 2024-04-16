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
        vector<ll> store(n);
        for(auto &ele:store) cin>>ele;
        bool flag=true;
        for(ll i=1;i<n-1;i++){
            ll temp=store[i-1];
            store[i-1]-=temp;
            store[i]-=2*temp;
            store[i+1]-=temp;
            if(store[i]<0 || store[i+1]<0){
                flag=false;
                break;
            }
        }
        if(!flag || store[n-1]>0 || store[n-2]>0) cout<<"NO"<<"\n";
        else cout<<"YES"<<"\n";
    }
    return 0;
}