/*It is not the matter of if, it the matter of when*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define all(x) begin(x), end(x)
int main() {
    string s; cin>>s;
    vector<ll>freq(s.size(),0);
    freq[freq.size()-1]=0;
    for(ll i=0;i<freq.size()-1;i++){
        if(s[i]==s[i+1]) freq[i]=1;
    }
    for(ll i=1;i<freq.size();i++){
        freq[i]+=freq[i-1];
    }
    ll q; cin>>q;
    for(ll i=0;i<q;i++){
        ll l,r; cin>>l>>r;
        l--;
        r--;
        if(l==0) cout<<freq[r-1]<<"\n";
        else{
            cout<<freq[r-1]-freq[l-1]<<"\n";
        }
    }
}