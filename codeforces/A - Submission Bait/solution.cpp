/*It is not the matter of if, it is the matter of when*/
/**/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll tsts; cin >> tsts; while(tsts--)
#define all(x) begin(x), end(x)
#define push_back(x) emplace_back(x);
#define push(x) emplace(x);
#define insert(x) emplace(x);
int main() {
    fastio
    ll i=1;
    testcases {
        ll n; cin>>n;
        vector<ll>store(n);
        for(auto &ele:store) cin>>ele;
        vector<ll>freq(*max_element(all(store))+1);
        for(ll i=0;i<n;i++){
            freq[store[i]]++;
        }
        bool flag=false;
        for(ll i=0;i<freq.size();i++){
            if(freq[i]%2!=0){
                flag=true;
                break;
            }
        }
        if(flag) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
    return 0;
}