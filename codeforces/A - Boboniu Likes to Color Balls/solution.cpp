/*It is not the matter of if, it is the matter of when*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll tsts; cin >> tsts; while(tsts--)
#define all(x) begin(x), end(x)
// #define push_back(x) emplace_back(x);
#define push(x) emplace(x);
#define insert(x) emplace(x);
int main() {
    fastio
    testcases { 
        ll r,b,g,w; cin>>r>>g>>b>>w;
        vector<ll>store={r,b,g,w};
        // sort(all(store),greater<int>());
        // while(!store.back()){
        //     store.pop_back();
        // }
        bool flag=false;
        if(r==0 || g==0 || b==0) flag=true; 
        ll cntE=0,cntO=0;
        ll cnt1=0;
        for(auto &ele:store){
            if(ele%2==0) cntE++;
            else cntO++;
        }
        if(abs(cntE-cntO)==2 || abs(cntE-cntO)==4){
            if(cntO>cntE && flag) cout<<"NO"<<"\n";
            else cout<<"YES"<<"\n";
        }
        else cout<<"NO"<<"\n";
    }
    return 0;
}