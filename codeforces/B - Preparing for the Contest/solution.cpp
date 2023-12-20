#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll int tsts; cin >> tsts; while(tsts--)
int main(){
    fastio
    testcases{
        ll n,k;
        cin>>n>>k;
        vector<ll>frq(n);
        iota(frq.begin(),frq.end(),1);
        // k=((k%(n))+((n)))%((n));
        if(k==0){
            reverse(frq.begin(),frq.end());
        }
        else{
            reverse(frq.begin()+1,frq.end());
            reverse(frq.begin()+1,frq.begin()+k+1);
        }
        for(auto i:frq){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}