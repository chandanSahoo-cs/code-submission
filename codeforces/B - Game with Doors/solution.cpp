/*It is not the matter of if, it is the matter of when*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll tsts; cin >> tsts; while(tsts--)
#define all(x) begin(x), end(x)
// #define push_back(x) emplace_back(x);
#define push(x) emplace(x);
#define insert(x) emplace(x);
int main() {
    fastio
    testcases { 
        ll al,ar,bl,br; cin>>al>>ar>>bl>>br;
        vector<ll>freq(100+1);
        for(ll i=1;i<101;i++){
            if(i>=al && i<=ar) freq[i]+=1;
            if(i>=bl && i<=br) freq[i]+=2;
        }
        ll cnt=0;
        for(ll i=min(min(al,ar),min(bl,br));i<max(max(al,ar),max(bl,br));i++){
            if(freq[i]==1 && freq[i+1]==0){
                cnt++;
                break;
            }
            else if(freq[i]==2 && freq[i+1]==0 ){
                cnt++;
                break;
            }
            if(freq[i]!=freq[i+1] && freq[i]!=0 && freq[i+1]!=0){
                cnt++;
            }
            else if(freq[i]==freq[i+1] && (freq[i]==3 || freq[i]==0)){
                cnt++;
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}