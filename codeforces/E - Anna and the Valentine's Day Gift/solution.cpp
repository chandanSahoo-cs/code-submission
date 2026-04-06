/*It is happening, right here and now*/
        
#include "bits/stdc++.h"
using namespace std;
 
#define velociraptor ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);                                             
#define all(v) v.begin(),v.end()
#define lcd(a,b) (a*b)/__gcd(a,b)
#define ll long long
 
const int mod = 1e9+7;
 
#ifdef chandan  
#include "starPlatinum.h"
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif
 
ll change(ll n){
    ll temp = 0;
 
    while(n){
        temp*=10;
        temp+=n%10;
        n/=10;
    }
 
    return temp;
}
 
ll calcLen(ll n){
    ll len = 0;
 
    while(n){
        len++;
        n/=10;
    }
 
    return len;
}
 
ll endZero(ll n){
    ll zero = 0;
 
    while(n%10==0){
        zero++;
        n/=10;
    }
 
    return zero;
}
 
void realmsDomain(){
   ll n,m ; cin>>n>>m;
   vector<ll>a(n);
 
   for(auto &ele:a) cin>>ele;
 
   sort(all(a),[&](ll i, ll j){
    return endZero(i)>endZero(j);
   });
    
   bool turn  = true;
   ll len = 0;
 
   for(auto &ele:a){
    if(ele%10==0){
        if(turn){
            ele = change(ele);
        }
        turn=!turn;
    }
    len+=calcLen(ele);
   }
 
   if(len>=m+1) cout<<"Sasha\n";
   else cout<<"Anna\n";
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