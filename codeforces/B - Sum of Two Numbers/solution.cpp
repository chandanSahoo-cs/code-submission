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
 
ll digiSum(ll n){
    ll sum = 0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}
 
void realmsDomain(){
    ll n; cin>>n;
    deb(n);
    if(n%10!=9){
        cout<<n/2<<" "<<n-n/2<<"\n";
    }
    else{
        ll div = 10;
        while((n%div)/(div/10)==9){
            ll add = n%div;
            deb(div);
            ll nt = n;
            nt-=add;
            deb(nt);
            if(abs(digiSum(nt/2)-digiSum(nt/2+add))==0){
                cout<<nt/2<<" "<<nt/2+add<<"\n";
                return;
            }
            else if(abs(digiSum(nt/2+5))-digiSum(nt/2+add-5)==1){
                cout<<nt/2+5<<" "<<nt/2+add-5<<"\n";
                return;
            }
            div*=10;
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