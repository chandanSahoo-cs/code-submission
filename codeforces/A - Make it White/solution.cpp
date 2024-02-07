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
        string s; cin>>s;
        ll strtIndx=0,endIndx=0;
        for(int i=0;i<n;i++){
            if(s[i]=='B'){
                strtIndx=i;
                break;
            }
        }
        for(ll i=n-1;i>=0;i--){
            if(s[i]=='B'){
                endIndx=i;
                break;
            }
        }
        cout<<endIndx-strtIndx+1<<"\n";
    }
    return 0;
}