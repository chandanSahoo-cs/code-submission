/*It is not the matter of if, it is the matter of when*/
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
    testcases {
        ll n; cin>>n;
        string s; cin>>s;
        string s1="";
        bool flag=false;
        for(ll i=0;i<n;i++){
            if(s[i]=='1'){
                s1+=s[i];
                flag=false;
            }
            else if(s[i]=='0' && !flag){
                s1+=s[i];
                flag=true;
            }
        }
        ll cnt1=0,cnt0=0;
        for(ll i=0;i<s1.size();i++){
            if(s1[i]=='1') cnt1++;
            else cnt0++;
        }
        if(cnt1>cnt0) cout<<"Yes"<<"\n";
        else cout<<"No"<<"\n";
    }
    return 0;
}