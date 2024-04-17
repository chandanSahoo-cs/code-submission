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
        ll a,b,l; cin>>a>>b>>l;
        ll aPow=0,bPow=0;
        while(pow(a,aPow)<=l) aPow++;
        while(pow(b,bPow)<=l) bPow++;
        set<ll>ans;
        for(ll i=0;i<aPow;i++){
            for(ll j=0;j<bPow;j++){
                ll temp1=pow(a,i);
                ll temp2=pow(b,j);
                if(l%(temp1*temp2)==0) ans.insert(l/(temp1*temp2));
            }
        }
        cout<<ans.size()<<"\n";
    }
    return 0;
}