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
        vector<char>store(n);
        for(auto &ele:store){
            cin>>ele;
        }
        ll thrnCnt=0;
        ll cnCnt=0;
        for(ll i=1;i<n;i++){
            if(store[i]=='*') thrnCnt++;
            else if(store[i]=='@'){
                cnCnt++;
                thrnCnt=0;
            }
            else{
                thrnCnt=0;
            }
            if(thrnCnt>1) break;
        }
        cout<<cnCnt<<"\n";
    }
    return 0;
}