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
        vector<ll>store(n-1);
        for(auto &ele:store) cin>>ele;
        vector<ll>ans(n);
        ans[0]=store[0]+1;
        ll temp;
        for(ll i=0;i<n-1;i++){
            if(i<n-2){
                temp=((store[i+1]+ans[i]-1)/ans[i])*ans[i]+store[i];
                ans[i+1]=temp;
            }
            else{
                temp=ans[i]+store[i];
                ans[i+1]=temp;
            }
        }
        for(auto &ele:ans) cout<<ele<<" ";
        cout<<"\n";
    }
    return 0;
}