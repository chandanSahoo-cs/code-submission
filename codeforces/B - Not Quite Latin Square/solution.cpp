#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll int tsts; cin >> tsts; while(tsts--)
int main(){
    fastio
    testcases{
        vector<vector<char>> ltnSqr(3,vector<char>(3));
        for(ll i=0;i<3;i++){
            for(ll j=0;j<3;j++){
                cin>>ltnSqr[i][j];
            }
        }
        ll A=0 ,B=0 ,C=0;
        for(ll i=0;i<3;i++){
            for(ll j=0;j<3;j++){
                if(ltnSqr[i][j]=='A') A++;
                else if(ltnSqr[i][j]=='B') B++;
                else if(ltnSqr[i][j]=='C') C++;
            }
        }
        if(A==B)cout<<'C'<<endl;
        else if(B==C)cout<<'A'<<endl;
        else cout<<'B'<<endl;
    }
    return 0;
}