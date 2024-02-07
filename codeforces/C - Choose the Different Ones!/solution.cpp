#include <bits/stdc++.h>
using namespace std;
//It is not matter of if, it is matter of when
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll int tsts; cin >> tsts; while(tsts--)
int main() {
    fastio
    testcases {
        ll n,m,k; cin>>n>>m>>k;
        vector<ll>a(n);
        for(auto &ele:a){
            cin>>ele;
        }
        vector<ll>b(m);
        for(auto &ele:b){
            cin>>ele;
        }
        vector<ll>aCheck(k+1,0);
        vector<ll>bCheck(k+1,0);
        ll aCnt=0;
        ll bCnt=0;
        for(ll i=0;i<n;i++){
            if(a[i]<=k && aCheck[a[i]]!=1 ){
                aCheck[a[i]]++;
                aCnt++;
            }
        }
        for(ll i=0;i<m;i++){
            if(b[i]<=k && bCheck[b[i]]!=1){
                bCheck[b[i]]++;
                bCnt++;
            }
        }
        bool flag=true;
        vector<ll>check(k+1,0);
        for(int i=1;i<k+1;i++){
            check[i]=aCheck[i]+bCheck[i];
        }
        if(aCnt>=k/2 && bCnt>=k/2){
            for(ll i=1;i<k+1;i++){
                if(check[i]==0){
                    flag=false;
                    break;
                }
            }
            if(flag) cout<<"YES"<<"\n";
            else cout<<"NO"<<"\n";
        }
        else cout<<"NO"<<"\n";
    }
    return 0;
}