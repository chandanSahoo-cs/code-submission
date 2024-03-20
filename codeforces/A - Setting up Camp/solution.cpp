#include <bits/stdc++.h>
using namespace std;
//It is not matter of if, it is matter of when
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll int tsts; cin >> tsts; while(tsts--)
int main() {
    fastio
    testcases {
        ll a,b,c; cin>>a>>b>>c;
        bool flag=true;
        ll temp=0;
        if(b%3!=0){
            if(b%3==2){
                if(c>=1){
                    temp+=(b+2)/3+((c-1)+2)/3;
                }
                else flag=false;
            }
            else{
                if(c>=2) temp+=(b+2)/3+((c-2)+2)/3;
                else flag=false;
            }
        }
        else temp+=b/3+(c+2)/3;
        if(flag) cout<<a+temp<<"\n";
        else cout<<-1<<"\n";
    }
    return 0;
}