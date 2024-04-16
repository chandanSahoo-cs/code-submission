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
        vector<ll> store(2*n);
        for(auto &ele:store) cin>>ele;
        vector<ll>freq1(n+1,0);
        vector<ll>freq2(n+1,0);
        for(ll i=0;i<n;i++){
            freq1[store[i]]++;
            freq2[store[n+i]]++;
        }
        // for(auto ele:freq1) cout<<ele<<" ";
        // cout<<"\n";
        // for(auto ele:freq2) cout<<ele<<" ";
        // cout<<"\n";
        vector<ll>sset1;
        vector<ll>sset2;
        ll temp1=2*k;
        ll temp2=2*k;
        if(temp1>0){
            for(ll i=0;i<n+1;i++){
                if(freq1[i]>1){
                    sset1.push_back(i);
                    sset1.push_back(i);
                    temp1-=2;
                }
                if(temp1==0) break;
            }
        }
        if(temp2>0){
            for(ll i=0;i<n+1;i++){
                if(freq2[i]>1){
                    sset2.push_back(i);
                    sset2.push_back(i);
                    temp2-=2;
                }
                if(temp2==0) break;
            }
        }
        ll temp=temp1;
        for(ll i=0;i<n+1;i++){
            if(freq1[i]==1) {
                sset1.push_back(i);
                sset2.push_back(i);
                temp--;
            }
            if(temp==0) break;
        }
        for(auto ele:sset1) cout<<ele<<" ";
        cout<<"\n";
        for(auto ele:sset2) cout<<ele<<" ";
        cout<<"\n";
    }
    return 0;
}