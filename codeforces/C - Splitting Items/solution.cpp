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
        ll n,k; cin>>n>>k;
        vector<ll>store(n);
        for(auto &ele:store) cin>>ele;
        sort(all(store),greater<int>());
        for(ll i=0;i<n;i+=2){
            if(i+1>=n){
                break;
            }
            if(store[i]>store[i+1]){
                if(k>=store[i]-store[i+1]){
                    k-=store[i]-store[i+1];
                    store[i+1]=store[i];
                }
                else{
                    store[i+1]+=k;
                    break;
                }
            }
        }
        bool flag=false;
        ll a=0,b=0;
        for(ll i=0;i<n;i++){
            if(!flag) a+=store[i];
            if(flag) b+=store[i];
            flag=!flag;
        }
        cout<<a-b<<"\n";
    }
    return 0;
}