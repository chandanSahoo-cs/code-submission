#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll tsts; cin >> tsts; while(tsts--)
#define all(x) begin(x), end(x)
int main() {
    fastio
    testcases {
        ll x,y,k; cin>>x>>y>>k;
        while(k>0){
            if(x==1){
                x+=(k)%(y-1);
                break;
            }
            ll t=(y-(x%y));
            if(k>=t){
                k-=t;
                x+=t;
            }
            else{
                x+=k;
                break;
            }
            while((x)%y==0){
                x/=y;
            }
        }
        cout<<x<<"\n";
    }
    return 0;
}
