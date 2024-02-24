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
        for(auto &ele:store) cin>>ele;
        // bool start=false;
        ll cnt=0;
        ll frstOccur;
        ll scndOccur;
        for(ll i=0;i<n;i++){
            if(store[i]==1){
                frstOccur=i;
                break;
            }
        }
        for(ll i=n-1;i>=0;i--){
            if(store[i]==1){
                scndOccur=i;
                break;
            }
        }
        for(ll i=0;i<n;i++){
            if(store[i]==0 && i>frstOccur && i<scndOccur) cnt++;
        }
        cout<<cnt<<"\n";
    }
    return 0;
}