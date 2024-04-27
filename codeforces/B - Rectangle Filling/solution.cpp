//**It is not matter of if, it is matter of when**
// #include <chandan/skills.h>
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll int tsts; cin >> tsts; while(tsts--)
int main() {
    fastio
    testcases {
        ll n,m; cin>>n>>m;
        vector<string>store(n);
        for(auto &ele:store) cin>>ele;
        bool topW=false,topB=false,botW=false,botB=false,rgtW=false,rgtB=false,lftW=false,lftB=false;;
        for(ll i=0;i<m;i++){
            if(store[0][i]=='W'){
                topW=true;
            }
            if(store[0][i]=='B'){
                topB=true;
            }
        }
        for(ll i=0;i<m;i++){
            if(store[n-1][i]=='W'){
                botW=true;
            }
            if(store[n-1][i]=='B'){
                botB=true;
            }
        }
        for(ll i=0;i<n;i++){
            if(store[i][0]=='W'){
                lftW=true;
            }
            if(store[i][0]=='B'){
                lftB=true;
            }
        }
        for(ll i=0;i<n;i++){
            if(store[i][m-1]=='W'){
                rgtW=true;
            }
            if(store[i][m-1]=='B'){
                rgtB=true;
            }
        }
        if((topW && botW && lftW && rgtW) || (topB && botB && lftB && rgtB)) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
    return 0;
}