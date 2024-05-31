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
        ll n; cin>>n;
        vector<ll>a(n),b(n+1);
        for(auto &ele:a) cin>>ele;
        for(auto &ele:b) cin>>ele;
        ll ans=0;
        for(ll i=0;i<n;i++){
            ans+=abs(b[i]-a[i]);
        }
        ll add=2e9;
        for(ll i=0;i<n;i++){
            if(min(b[i],a[i])<b[n] && max(b[i],a[i])>b[n]){
                add=1;
                break;
            }
            else{
                add=min(min(add,abs(b[n]-a[i])+1),abs(b[n]-b[i])+1);
            }
        }
        cout<<ans+add<<"\n";
    }
    return 0;
}