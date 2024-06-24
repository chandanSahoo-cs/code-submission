#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll tsts; cin >> tsts; while(tsts--)
#define all(x) begin(x), end(x)
int main() {
    fastio
    testcases {
        ll n, m; cin>>n>>m;
        vector<vector<ll>>store(n,vector<ll>(m));
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                cin>>store[i][j];
            }
        }
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                ll up,down,right,left;
                if(j+1==m) down=0;
                else down=store[i][j+1];
                if(j-1<0) up=0;
                else up=store[i][j-1];
                if(i+1==n) right=0;
                else right=store[i+1][j];
                if(i-1<0) left=0;
                else left=store[i-1][j];
                store[i][j]=min(store[i][j],max(max(up,down),max(right,left)));
            }
        }
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                cout<<store[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}