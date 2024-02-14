#include <bits/stdc++.h>
using namespace std;
//It is not matter of if, it is matter of when
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll int tsts; cin >> tsts; while(tsts--)
int main() {
    fastio
    testcases {
        ll n; cin>>n;
        vector<ll>store(n);
        ll sum=0;
        for(auto &ele:store) {
            cin>>ele;
            sum+=ele;
        }
        ll noRqurd=sum/n;
        ll temp=0;
        bool flag=true;
        for(ll i=0;i<n;i++){
            if(store[i]>=noRqurd){
                temp+=(store[i]-noRqurd);
            }
            else{
                ll temp1=noRqurd-store[i];
                temp-=temp1;
                if(temp<0){
                    flag=false;
                    break;
                }
            }
        }
        if(flag) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
    return 0;
}