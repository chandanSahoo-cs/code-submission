#include <bits/stdc++.h>
using namespace std;
//It is not matter of if, it is matter of when
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll int tsts; cin >> tsts; while(tsts--)
int main() {
    fastio
    testcases {
        ll n; cin>>n;
        vector<ll>trace(n);
        for(auto &ele:trace){
            cin>>ele;
        }
        vector<ll>alpha(26,0);
        string str="";
        for(ll i=0;i<n;i++){
            ll target=trace[i];
            for(ll j=0;j<26;j++){
                if(alpha[j]==target){
                    str+=static_cast<char>(j+'a');
                    alpha[j]++;
                    break;
                }
            }
        }
        cout<<str<<"\n";
    }
    return 0;
}