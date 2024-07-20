/*It is not the matter of if, it is the matter of when*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll tsts; cin >> tsts; while(tsts--)
#define all(x) begin(x), end(x)
int main() {
    fastio
    testcases {
        ll n,x,y; cin>>n>>x>>y;
        vector<ll>store(n,1);
        for(ll i=0;i<n;i++){
            if(i+1>x) store[i]=-1;
            else if(i+1<y) store[i]=-1;
        }
        bool flag=false;
        for(ll i=y-2;i>=0;i--){
            if(!flag){
                store[i]=-1;
                flag=true;
            }
            else{
                store[i]=1;
                flag=false;
            }
        }
 
        flag=false;
        for(ll i=x;i<n;i++){
            if(!flag){
                store[i]=-1;
                flag=true;
            }
            else{
                store[i]=1;
                flag=false;
            }
        }
        for(auto ele:store) cout<<ele<<" ";
        cout<<"\n";
    }
    return 0;
}