#include "bits/stdc++.h"
using namespace std;
 
#define velociraptor ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);                                             
#define all(v) v.begin(),v.end()
#define lcd(a,b) a*(b/__gcd(a,b))
#define ll long long
 
const int mod = 1e9+7;
 
#ifdef chandan  
#include "starPlatinum.h"
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif
 
ll binExpMod(ll base, ll exp, ll mod) {
    ll result = 1;
    base = base % mod;
    
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    
    return result;
}
 
void realmsDomain(){
    ll l,r,x; cin>>l>>r>>x;
    ll a,b; cin>>a>>b;
    ll diff = abs(a-b);
    if(diff==0) cout<<0<<"\n";
    else if(x<=diff){
        cout<<1<<"\n";
    }
    else{
        if(b>a){
            if(b+x<=r){
                cout<<2<<"\n";
            }
            else if(b-x>=l && a-x>=l){
                cout<<2<<"\n";
            }
            else if(a+x<=r && b-x>=l ){
                cout<<3<<"\n";
            }
            else cout<<-1<<"\n";
        }
        else{
            if(b-x>=l){
                cout<<2<<"\n";
            }
            else if(b+x<=r && a+x<=r){
                cout<<2<<"\n";
            }
            else if(a-x>=l && b+x<=r){
                cout<<3<<"\n";
            }
            else cout<<-1<<"\n";
        }
    }
}
 
int main() {
    clock_t time_req = clock();
    velociraptor
 
 
    #ifdef chandan 
    freopen("error.txt", "w", stderr); 
    #endif
 
    ll tsts = 1 ; 
 
    cin>>tsts;    
 
    for(ll testcase = 1 ; testcase <=  tsts ; testcase++ ){
        realmsDomain();
    }
 
    #ifdef chandan
    cerr << "Time : " << fixed << setprecision(6) << ((double)(clock() - time_req)) / CLOCKS_PER_SEC << endl;
    #endif
 
    return 0;
}