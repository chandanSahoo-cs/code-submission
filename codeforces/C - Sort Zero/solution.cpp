#include "bits/stdc++.h"
using namespace std;
 
#define velociraptor ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(v) v.begin(),v.end()
#define lcd(a,b) a*(b/__gcd(a,b))
#define ll long long
 
void realmsDomain(){
    ll n; cin>>n;
    vector<ll>a(n);
    for(auto &ele:a) cin>>ele;
    
    set<ll>st;
    vector<ll>mark(n+1,1);
    ll cnt=0;
    for(ll i=0;i<n-1;i++){
        if(mark[a[i]]==0){
            a[i]=0;
        }
        
        if(mark[a[i+1]]==0){
            a[i+1]=0;
        }
        if(a[i]!=0){
            st.insert(a[i]);
        }
 
        if(a[i]>a[i+1]){
            cnt+=st.size();
            while(!st.empty()){
                mark[*st.begin()]=0;
                st.erase(*st.begin());
            }
        }
    }
// 1 3 1 3
    cout<<cnt<<"\n";
}
 
int main() {
    velociraptor
    ll tsts = 1 ; cin>>tsts;
    for(ll testcase = 1 ; testcase <=  tsts ; testcase++ ){
        realmsDomain();
    }
    return 0;
}