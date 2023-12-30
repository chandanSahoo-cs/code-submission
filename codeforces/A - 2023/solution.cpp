#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll int tsts; cin >> tsts; while(tsts--)
 
int main() {
    fastio
    testcases {
        ll n, k;
        cin >> n >> k;
        vector<ll> seqb(n);
        ll prcseqb = 1;
        for (auto &ele : seqb) {
            cin >> ele;
            prcseqb *= ele;
        }
        vector<ll> freq(k,1);
        if(2023%prcseqb==0){
            cout<<"YES"<<"\n";
            if(2023/prcseqb==7){
                freq[0]=7;
            }
            else if(2023/prcseqb==17){
                freq[0]=17;
            }
            else if(2023/prcseqb==289){
                freq[0]=289;
            }
            else if(2023/prcseqb==2023){
                freq[0]=2023;
            }
            else if(2023/prcseqb==119){
                freq[0]=119;
            }
            for(auto ele:freq){
                cout<<ele<<" ";
            }
            cout<<"\n";
        }
        else{
            cout<<"NO"<<'\n';
        }
    }
 
    return 0;
}