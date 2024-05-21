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
        ll x,y; cin>>x>>y;
        ll toty=(y+1)/2;
        ll totx=x-(toty*15-y*4);
        if(totx<0) cout<<toty<<"\n";
        else cout<<(totx+14)/15+toty<<"\n";
    }
    return 0;
}