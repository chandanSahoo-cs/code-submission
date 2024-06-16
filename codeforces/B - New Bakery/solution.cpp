#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll tsts; cin >> tsts; while(tsts--)
#define all(x) begin(x), end(x)
int main() {
    fastio
    testcases {
        ll n,a,b; cin>>n>>a>>b; 
        ll sum=0;
        ll temp=(max((ll)0,b-a));
        ll temp2=max((ll)0,temp-n);
        temp-=temp2;
        ll tempSum=(temp*(b+(b-temp+1)))/2;
        ll tempSum2=max(n-temp,(ll)0)*a;
        cout<<tempSum+tempSum2<<"\n";
    }
    return 0;
}