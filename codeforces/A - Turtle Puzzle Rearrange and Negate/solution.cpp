#include <bits/stdc++.h>
using namespace std;
//It is not matter of if, it is matter of when
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll int tsts; cin >> tsts; while(tsts--)
int main() {
    fastio
    testcases {
      ll n; cin>>n;
      vector<ll>store(n);
      ll sum=0;
      for(auto &ele:store) cin>>ele,sum+=abs(ele);
      cout<<sum<<"\n";
    }        
    return 0;
}