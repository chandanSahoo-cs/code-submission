#include <bits/stdc++.h>
using namespace std;
//It is not matter of if, it is matter of when
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll int tsts; cin >> tsts; while(tsts--)
bool divCheck(ll n,ll i,vector<ll>&div){
    if(n==1) return true;
    while(i>=0){
        if(n%div[i]==0){
            if(!divCheck(n/div[i],i,div)) return false;
            else return true;
        }
        else i--;
    }
    return false;
}
int main() {
    fastio
    testcases {
        ll n; cin>>n;
        vector<ll>div={10, 11, 100, 101, 110, 111, 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111,10000, 10001, 10010, 10011, 10100, 10101, 10110, 10111, 11000, 11001, 11010,11011, 11100, 11101, 11110, 11111, 100000};
        bool flag=true;
        if(n==0 || n==1) cout<<"YES"<<"\n";
        else if(divCheck(n,31,div)) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
    return 0;
}