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
        ll mex=0;
        set<ll>st;
        for(ll i=0;i<n;i++){
            bool flag=false;
            while(!flag){
                if(st.find(mex)!=st.end()){
                    mex++;
                }
                if(st.find(mex)==st.end()) {
                    flag=true;
                    
                }
            }
            if(store[i]<0){
                cout<<mex-store[i]<<" ";
                st.insert(mex-store[i]);
            }
            else {
                st.insert(mex);
                cout<<mex++<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}