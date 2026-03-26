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
 
void realmsDomain(){
   string s,t; cin>>s>>t;
 
   int n = s.size(), m = t.size();
 
   for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
        int idx = 0, x = i;
 
        while(x<=j && idx<m && s[x]==t[idx]){
            x++;
            idx++;
        }
 
        x-=2;
        while(x>=0 && idx<m && s[x]==t[idx]){
            x--;
            idx++;
        }
 
        if(idx==m){
            cout<<"YES\n";
            return;
        }
    }
   } 
 
   cout<<"NO\n";
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