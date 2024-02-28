#include <bits/stdc++.h>
using namespace std;
//It is not matter of if, it is matter of when
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll int tsts; cin >> tsts; while(tsts--)
int main() {
    fastio
    testcases {
        ll n; cin>>n;
        vector<ll>store(n);
        ll sum=0;
        for(auto &ele: store) cin>>ele, sum+=ele;
        if(sum%3==0) cout<<0<<"\n";
        else if(sum%3==2) cout<<1<<"\n";
        else{
            bool flag=false;
            for(ll i=0;i<n;i++){
                if (store[i]%3==1) flag=true;
            }
            if(flag) cout<<1<<"\n";
            else cout<<2<<"\n";
        }
    }
    return 0;
}