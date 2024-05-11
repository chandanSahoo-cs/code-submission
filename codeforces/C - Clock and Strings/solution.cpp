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
        ll a,b,c,d; cin>>a>>b>>c>>d; 
        if(a>b) swap(a,b);
        if(c>a && c<b){
            if(d<a || d>b ) cout<<"YES"<<"\n";
            else cout<<"NO"<<"\n";
        }
        else if(d>a && d<b){
            if(c<a || c>b ) cout<<"YES"<<"\n";
            else cout<<"NO"<<"\n";
        }
        else cout<<"NO"<<"\n";
    }
    return 0;
}