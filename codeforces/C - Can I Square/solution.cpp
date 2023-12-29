#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll int tsts; cin >> tsts; while(tsts--)
int main(){
    fastio
    testcases{
        ll n;
        cin>>n;
        vector<ll> sqr(n);
        for( ll &ele:sqr){
            cin>>ele;
        }
        ll sm=0;
        for(ll ele:sqr){
            sm+=ele;
        }
        ll sqrtNm=sqrt(sm);
        if(sqrtNm*sqrtNm==sm) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}