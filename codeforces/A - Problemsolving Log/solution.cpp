#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll int tsts; cin >> tsts; while(tsts--)
int main(){
    fastio
    testcases{
        ll n; string s;
        cin>>n>>s;
        vector<ll>frq(27,0);
        ll cnt=0;
        for( auto c:s){
            frq[int(c)-'A'+1]++;
        }
        for(int i=1;i<frq.size();i++){
            if(frq[i]!=0){
                if(frq[i]>=i){
                    n-=frq[i];
                    if(n<0) break;
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
}