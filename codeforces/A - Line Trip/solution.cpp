#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long
#define testcases ll int tsts; cin >> tsts; while(tsts--)
int main(){
    fastio
    testcases{
        int x,n;
        cin>>n>>x;
        vector<int>fuel(n+1);
        fuel[0]=0;
        for(int i=1;i<=n;i++){
            cin>>fuel[i];
        }
        vector<int>prefixSub(n);
        for(int i=0;i<n;i++){
            prefixSub[i]=abs(fuel[i]-fuel[i+1]);
        }
        auto maxFuel=*max_element(prefixSub.begin(),prefixSub.end());
        int fuelly=maxFuel;
        int finalFuel=max(fuelly,abs(2*(fuel[n]-x)));
        cout<<finalFuel<<endl;
    }
    return 0;
}