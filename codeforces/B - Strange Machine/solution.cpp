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
   ll n,q; cin>>n>>q;
   string s; cin>>s;
 
   vector<int>act;
 
   int cnt=0;
   bool flag=false;
 
   for(int i=0;i<n;i++){
    if(s[i]=='A'){
        cnt++;
    }else{
        if(cnt>0){
            act.push_back(cnt);
            cnt=0;
        }
 
        act.push_back(-1);
        flag=true;
    }
   }
   if(cnt>0){
    act.push_back(cnt);
   }
 
   deb(act);
 
   for(int i=0;i<q;i++){
    int ele; cin>>ele;
 
    if(!flag){
        cout<<ele<<"\n";
    }else{
        int j=0;
        int keep=0;
        while(ele){
            deb(ele);
            if(act[j]!=-1){
                keep+=min(ele,act[j]);
                ele-=min(ele,act[j]);
            }else{
                ele = ele/2;
                keep++;
            }
            j = (j+1)%act.size();
        }
 
        cout<<keep<<"\n";
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