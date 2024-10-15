#include "bits/stdc++.h"
using namespace std;
 
#define velociraptor ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(v) v.begin(),v.end()
#define lcd(a,b) a*(b/__gcd(a,b))
#define ll long long
 
void realmsDomain(){
    ll n,k; cin>>n>>k;
    vector<ll>a(n);
    for(auto &ele:a) cin>>ele;
 
    map<ll,ll>mp;
    for(auto ele:a) mp[ele]++;
 
    vector<pair<ll,ll>>cnted;
    for(auto ele:mp) cnted.push_back(ele);
 
    ll kCnt=1;
    ll mxSum=cnted[0].second;
    ll tempSum=cnted[0].second;
    ll i=0,j=1;
    while(i<=j && j<(ll)cnted.size()){
        if(cnted[j].first-1>cnted[j-1].first){
            kCnt=1;
            tempSum=cnted[j].second;
            i=j,j++;
        }
        else if(kCnt<k){
            tempSum+=cnted[j++].second;
            kCnt++;
        }
        else if(kCnt==k){
            tempSum-=cnted[i++].second;
            kCnt--;
        }
        mxSum=max(mxSum,tempSum);
    }
    cout<<mxSum<<"\n";
}
 
int main() {
    velociraptor
    ll tsts = 1 ; cin>>tsts;
    for(ll testcase = 1 ; testcase <=  tsts ; testcase++ ){
        realmsDomain();
    }
    return 0;
}