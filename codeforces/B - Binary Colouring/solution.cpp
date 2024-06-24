#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll tsts; cin >> tsts; while(tsts--)
#define all(x) begin(x), end(x)
int main() {
    fastio
    testcases {
        ll x; cin>>x;
        vector<ll>store(32,0);
        while(x>=1){
            store[(ll)log2(x)]=1;
            x-=pow(2,(ll)log2(x));
        }
        cout<<32<<"\n";
        bool check=false;
        for(ll i=1;i<32;i++){
            if(store[i]==1 && store[i-1]==1){
                store[i-1]=-1;
                store[i]=0;
                check=true;
            }
            else if(check && store[i]==1){
                store[i]=0;
            }
            else if(check && store[i]==0){
                store[i]=1;
                check=false;
            }
        }
        for(ll i=0;i<32;i++){
            cout<<store[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
