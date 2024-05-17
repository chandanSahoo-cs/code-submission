//**It is not matter of if, it is matter of when**
// #include <chandan/skills.h>
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll int tsts; cin >> tsts; while(tsts--)
int main() {
    fastio
    testcases {
        ll a,b,c; cin>>a>>b>>c;
        ll mtch=a+b+c;
        if(mtch%2!=0){
            cout<<-1<<"\n";
        }
        else{
            vector<ll>res;
            res.push_back(a);
            res.push_back(b);
            res.push_back(c);
            ll cnt=0;
            while(res[1]>0){
                res[1]--;
                res[2]--;
                cnt++;
                sort(res.begin(),res.end());
            }
            cout<<cnt<<"\n";
        }
    }
    return 0;
}