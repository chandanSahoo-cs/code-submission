/*It is not the matter of if, it is the matter of when*/
/**/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll tsts; cin >> tsts; while(tsts--)
#define all(x) begin(x), end(x)
int main() {
    fastio
    testcases {
        ll n; cin>>n;
        vector<ll>store(n);
        for(auto &ele:store) cin>>ele;
        string s; cin>>s;
        ll strt=0,end=n-1;
        vector<ll>pref(n);
        pref[0]=store[0];
        for(ll i=1;i<n;i++){
            pref[i]=pref[i-1]+store[i];
        }
        ll sum=0;
        while(strt<end){
            if(s[strt]=='L' && s[end]=='R'){
                if(strt==0){
                    sum+=pref[end];
                }
                else{
                    sum+=pref[end]-pref[strt-1];
                }
                strt++;
                end--;
            }
            if(s[strt]=='R') strt++;
            if(s[end]=='L') end--;
        }
        cout<<sum<<"\n";
    }
    return 0;
}