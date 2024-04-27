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
        ll n,k; cin>>n>>k;
        vector<ll>store(n);
        for(auto &ele:store) cin>>ele;
        vector<ll>freq(101);
        for(ll i=0;i<n;i++){
            freq[store[i]]++;
        }
        bool flag=false;
        for(ll i=0;i<101;i++){
            if(freq[i]>=k){
                flag=true;
                break;
            }
        }
        if(flag) cout<<k-1<<"\n";
        else cout<<n<<"\n";
    }
    return 0;
}