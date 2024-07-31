/*It is not the matter of if, it is the matter of when*/
/**/
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
        string s1; cin>>s1;
        string s2; cin>>s2;
        ll cnt=0;
        //for upar
        for(ll i=1;i<n-1;i++){
            if(s1[i]=='.'){
                if(s2[i-1]=='x' && s2[i+1]=='x' && s1[i-1]!='x' && s1[i+1]!='x' && s2[i]!='x'){
                    cnt++;
                }
            }
        }
        for(ll i=1;i<n-1;i++){
            if(s2[i]=='.'){
                if(s1[i-1]=='x' && s1[i+1]=='x' && s2[i-1]!='x'&& s2[i+1]!='x' &&  s1[i]!='x'){
                    cnt++;
                }
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}