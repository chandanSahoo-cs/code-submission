/*It is not the matter of if, it is the matter of when*/
/**/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll tsts; cin >> tsts; while(tsts--)
#define all(x) begin(x), end(x)
#define push_back(x) emplace_back(x);
#define push(x) emplace(x);
#define insert(x) emplace(x);
int main() {
    fastio
    testcases {
        ll n,k; cin>>n>>k;
        if(k==0){
            cout<<0<<"\n";
            continue;
        }
        ll cnt=1;
        k-=n;
        n--;
        while(k>0){
            k-=n;
            if(k>0){
                k-=n;
                cnt+=2;
            }
            else {
                cnt+=1;
                break;
            }
            n--;
        }
        cout<<cnt<<"\n";
    }
    return 0;
}