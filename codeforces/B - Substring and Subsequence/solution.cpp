#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll tsts; cin >> tsts; while(tsts--)
#define all(x) begin(x), end(x)
int main() {
    fastio
    testcases {
        string s1; cin>>s1;
        string s2; cin>>s2;
        ll ans=0;
        ll cnt=0;
        bool flag=false;
        ll store=0;
        for(ll i=0;i<s2.size();i++){
            cnt=0;
            for(ll j=i,k=0;j<s2.size(),k<s1.size();k++){
                if(s2[j]==s1[k]){
                    cnt++;
                    ans=max(ans,cnt);
                    j++;
                }
            }
        }
        cout<<s1.size()+s2.size()-ans<<"\n";
    }
    return 0;
}