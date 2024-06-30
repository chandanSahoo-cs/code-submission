#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll tsts; cin >> tsts; while(tsts--)
#define all(x) begin(x), end(x)
ll cntSum(ll x){
    ll sum=0;
    while(x>0){
        sum+=x%10;
        x/=10;
    }
    return sum;
}
int main() {
    fastio
    testcases {
        ll x,k; cin>>x>>k;
        bool flag=false;
        while(!flag){
            if(cntSum(x)%k==0){
                flag=true;
                break;
            }
            else x++;
        }
        cout<<x<<"\n";
    }
    return 0;
}