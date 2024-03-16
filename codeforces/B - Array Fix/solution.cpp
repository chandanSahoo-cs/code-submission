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
        stack<ll>storeStck;
        storeStck.push(store[n-1]);
        bool flag=true;
        for(ll i=n-2;i>=0;i--){
            if(storeStck.top()<store[i]){
                ll temp=store[i];
                ll dg1=temp%10;
                temp/=10;
                ll dg2=temp%10;
                if(dg2>dg1 || dg1>storeStck.top()){
                    flag=false;
                    break;
                }
                else{
                    storeStck.push(store[i]);
                    storeStck.push(dg1);
                    storeStck.push(dg2);
                }
            }
            else{
                storeStck.push(store[i]);
            }
        }
        if(flag) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
    return 0;
}