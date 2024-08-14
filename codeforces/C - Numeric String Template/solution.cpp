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
int ALPHA=26;
int main() {
    fastio
    testcases { 
        ll n; cin>>n;
        vector<ll>store(n);
        for(auto &ele:store) cin>>ele;
        
        ll m; cin>>m;
        vector<string>stringStore(m);
        for(auto &ele:stringStore) cin>>ele;
        for(ll i=0;i<m;i++){
            bool flag=true;
            if(stringStore[i].size()!=n){
                flag=false;
            }
            else{
                map<ll,set<char>>mp1;
                map<char,set<ll>>mp2;
                for(ll j=0;j<n;j++){
                    mp1[store[j]].insert(stringStore[i][j]);
                    mp2[stringStore[i][j]].insert(store[j]);
                    if(mp1[store[j]].size()>1 || mp2[stringStore[i][j]].size()>1){
                        flag=false;
                        break;
                    }
                }
            }
            if(flag) cout<<"YES"<<"\n";
            else cout<<"NO"<<"\n";
        }
    }
    return 0;
}