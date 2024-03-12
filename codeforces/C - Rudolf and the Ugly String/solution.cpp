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
        ll cnt=0;
        ll indx=-2;
        for(ll i=1;i<n-1;i++){
            if(s[i]=='a' && s[i-1]=='m' && s[i+1]=='p'){
                if(indx+2!=i){
                    cnt++;
                    indx=i;
                }
            }
            else if(s[i]=='i' && s[i-1]=='p' && s[i+1]=='e'){
                if(indx+2!=i){
                    cnt++;
                    indx=i;
                }
            }
        }
        ll cnt2=0;
        // for(ll i=2;i<n;i++){
        //     if(s[i]=='p' && s[i-1]=='a' && s[i-2]== 'm' && s[i+1]=='i' && s[i+2]=='e') cnt2++;
        // }
        cout<<cnt<<"\n";
    }
    return 0;
}