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
        ll k,q; cin>>k>>q;
        vector<ll>a(k);
        vector<ll>n(q);
        for(auto &ele:a) cin>>ele;
        for(auto &ele:n) cin>>ele;
        for(ll i=0;i<q;i++){
            while(n[i]>=0){
                ll temp=n[i];
                for(ll j=k-1;j>=0;j--){
                    if(a[j]<=n[i]) n[i]--;
 
                }
                if(temp==n[i]) break;
            }
            cout<<n[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}