#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define all(x) begin(x), end(x)
 
int main() {
    fastio
    ll n; cin>>n;
    vector<ll>store(n);
    for(auto &ele:store) cin>>ele;
    map<ll,ll>freq;
    for(ll i=0;i<n;i++){
        freq[store[i]]++;
    }
    ll cnt=0;
    for(ll i=4;i>=1;i--){
        if(i==4) cnt+=freq[4];
        else if(i==3){
            freq[1]=freq[1]-freq[3]>0?freq[1]-freq[3]:0;
            cnt+=freq[i];
        }
        else if(i==2){
            cnt+=(freq[i]+1)/2;
            freq[i]%=2;
            freq[1]=freq[1]-2*freq[2]>0?freq[1]-2*freq[2]:0;
        }
        else {
            cnt+=(freq[i]+3)/4;
        }
    }
    cout<<cnt<<"\n";
}