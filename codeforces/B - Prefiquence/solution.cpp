//**It is not matter of if, it is matter of when**
// #include <chandan/skills.h>
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll int tsts; cin >> tsts; while(tsts--)
int main() {
    fastio
    testcases {
        int n,m; cin>>n>>m;
        string s1,s2; cin>>s1>>s2;
        ll i=0,j=0;
        ll k=0;
        while(i<n && j<m){
            if(s1[i]==s2[j]){
                i++;
                j++;
                k++;
            }
            else{
                j++;
            }
        }
        cout<<k<<"\n";
    }
    return 0;
}