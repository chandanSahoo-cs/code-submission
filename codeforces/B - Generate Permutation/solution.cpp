/*It is not the matter of if, it the matter of when*/
 
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long
#define ll long long
#define all(x) begin(x), end(x)
 
void solve()
{
    ll n; cin>>n;
    if(n%2==0){
        cout<<-1<<"\n";
    }
    else{
        for(ll i=1;i<=n/2;i++){
            cout<< n-i+1<<" " << i<<" ";
        }
        cout<<(n+1)/2<<"\n";
    }
}
 
int32_t main(){
    fastio
 
    int T=1;
    cin>>T;
 
    while(T--)
        solve();
 
    return 0;
}