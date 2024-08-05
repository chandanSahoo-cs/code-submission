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
        ll n; cin>>n;
        vector<ll>store(n);
        for(auto &ele:store) cin>>ele;
        ll cnt=0;
        ll oddMax=-1;
        vector<ll>evenEle;
        bool allOdd=true;
        bool allEven=true;
        for(ll i=0;i<n;i++){
            if(store[i]%2==0){
                allOdd=false;
                evenEle.push_back(store[i]);
            }
            else{
                allEven=false;
                oddMax=max(store[i],oddMax);
            }
        }
        if(allOdd || allEven) cout<<0<<"\n";
        else{
            sort(all(evenEle));
            ll sum=0;
            // cnt++;
            // oddMax+=evenEle[0];
            for(ll i=0;i<evenEle.size();i++){
                if(oddMax<evenEle[i]){
                    cnt++;
                    oddMax+=evenEle[i];
                }
                cnt++;
                oddMax+=evenEle[i];
            }
            // ll cnt2=0;
            // cnt2++;
            
            cout<<min((ll)cnt,(ll)evenEle.size()+1)<<"\n";
        }
    }
    return 0;
}