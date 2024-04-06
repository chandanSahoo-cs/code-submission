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
        ll myCw=store[k-1];
        ll cntf=0;
        ll ps=-1;
        for(ll i=0;i<n;i++){
            if(store[i]<=myCw) cntf++;
            else{
                ps=i;
                break;
            }
        }
        if(ps>k-1 || ps==-1) cout<<cntf-1<<"\n";
        else{
            ll cnttem=0;
            for(ll i=ps+1;i<k-1;i++){
                if(store[i]<myCw) cnttem++;
                else break;
            }
            if(cntf==0 && cnttem==0) cout<<0<<"\n";
            else cout<<max(cntf-1,cnttem+(ps!=0?1:0))<<"\n";
        }
    }
    return 0;
}