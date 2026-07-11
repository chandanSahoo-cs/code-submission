/*It is happening, right here and now*/
        
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
  ll n; cin>>n;
  string s; cin>>s;
 
  stack<int>st;
 
  vector<int>color(n);
 
  unordered_map<char,int>mp;
 
  for(int i=0;i<n;i++){
    if(st.empty()){
        if(mp.count(s[i])){
            color[i] = mp[s[i]];
        }else{
            if(mp.size()==1){
                mp[s[i]]=2;
                color[i]=2;
            }else{
                mp[s[i]]=1;
                color[i]=1;
            }
        }
        st.push(i);
    }else{
        color[i] = color[st.top()]; 
        if(s[st.top()]!=s[i]){
            st.pop();
        }else st.push(i);
    }
  }
 
  if(!st.empty()){
    cout<<-1<<"\n";
  }else{
    cout<<mp.size()<<"\n";
    for(int i=0;i<n;i++) cout<<color[i]<<" \n"[i==n-1];
  }
 
  return;
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