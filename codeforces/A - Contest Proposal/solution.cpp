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
        vector<ll>storeA(n);
        for(auto &ele:storeA) cin>>ele;
        vector<ll>storeB(n);
        for(auto &ele:storeB) cin>>ele;
        ll cnt=0;
        for(ll i=0;i<n;i++){
            if(storeA[i]>storeB[i]){
                cnt++;
                ll temp=storeA[i];
                storeA[i]=storeB[i];
                for(ll j=i+1;j<n;j++){
                    ll temp2=storeA[j];
                    storeA[j]=temp;
                    temp=temp2;
                }
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}