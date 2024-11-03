/*It is not the matter of if, it is the matter of when*/
        
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
 
 
void realmsDomain(){ 
    ll r,c; cin>>r>>c;
    vector<string>a(r);
    for(auto &ele:a) cin>>ele;
    deb(a);
    ll tr = r;
    ll tc = c;    
    vector<string>ans;
    ll cnt=0;
    ll ti=0,tj=0;
    while(cnt<r*c){
        string s = "";
        ll i=ti,j=tj;
        while(j<tc){
            s+=a[i][j++];
            cnt++;
        }
        j--;
        i++;
        while(i<tr){
            s+=a[i][j];
            i++;
            cnt++;
        }
        i--;
        j--;
        while(j>=tj){
            s+=a[i][j];
            j--;
            cnt++;
        }
        j++;
        i--;
        while(i>=ti+1){
            s+=a[i][j];
            i--;
            cnt++;
        }
        ans.push_back(s);
        tr--,tc--;
        ti++;
        tj++;
 
    }
    deb(ans);
    ll cnt1=0;
    for(ll i=0;i<(ll)ans.size();i++){
        ll m = ans[i].size();
        for(ll j=0;j<(ll)ans[i].size();j++){
            if(ans[i][j%m]=='1' && ans[i][(j+1)%m]=='5' && ans[i][(j+2)%m]=='4' && ans[i][(j+3)%m]=='3'){
                cnt1++;
            }
        }
    }
    cout<<cnt1<<"\n";    
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