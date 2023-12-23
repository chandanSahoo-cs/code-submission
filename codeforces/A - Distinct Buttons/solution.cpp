#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll int tsts; cin >> tsts; while(tsts--)
int main(){
    fastio
    testcases{
        ll n;
        cin>>n;
        vector<pair<int,int>>crds(n);
        for(auto &ele:crds){
            cin>>ele.first;
            cin>>ele.second;
        }
        sort(crds.begin(),crds.end());
        ll chckrX=0;
        ll chckrY=0;
        ll up=0;
        ll down=0;
        ll right=0;
        ll left=0;
        for(ll i=0;i<n;i++){
            if(crds[i].first>chckrX) right=1;
            else if(crds[i].first<chckrX) left=1;
 
            if(crds[i].second>chckrY) up=1;
            else if(crds[i].second<chckrY) down=1;
 
            // chckrX=crds[i].first;
            // chckrY=crds[i].second;
        }
        if(up+down+right+left<4)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}