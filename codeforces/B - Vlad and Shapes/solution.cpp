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
        vector<string>store(n);
        ll cnt=0;
        for(auto &ele:store) cin>>ele;
        for( ll i=0;i<n;i++){
            ll tempCnt=0;
            for(ll j=0;j<n;j++){
                if(store[i][j]=='1') tempCnt++;
            }
            if(tempCnt!=0 && cnt!=0){
                if(tempCnt!=cnt) cout<<"TRIANGLE"<<"\n";
                else cout<<"SQUARE"<<"\n";
                break;
            }
            cnt=tempCnt;
        }
    }
    return 0;
}