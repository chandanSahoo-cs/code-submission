#include <bits/stdc++.h>
using namespace std;
//It is not matter of if, it is matter of when
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll int tsts; cin >> tsts; while(tsts--)
int main() {
    fastio
    testcases {
        ll n,f,a,b; 
        cin>>n>>f>>a>>b;
        vector<ll>mmnt(n+1);
        mmnt[0]=0;
        for(ll i=1;i<n+1;i++){
            cin>>mmnt[i];
        }
        for(int i=1;i<n+1;i++){
            ll sub=min(b,a*(mmnt[i]-mmnt[i-1]));
            f-=sub;
        }
        if(f<=0) cout<<"No"<<"\n";
        else cout<<"Yes"<<"\n";
    }
    return 0;
}