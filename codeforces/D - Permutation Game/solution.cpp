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
        ll n,k,b,s; cin>>n>>k>>b>>s;
        vector<vector<ll>>store(n,vector<ll>(2));
        for(ll i=0;i<n;i++) cin>>store[i][0];
        for(ll i=0;i<n;i++) cin>>store[i][1];
        ll ansB=0;
        ll toMoveB=b-1;
        ll stepsB=0;
        ll kB=k;
        ll mxB=0;
        while(kB>0){
            ll val=store[toMoveB][1];
            mxB=max(val*kB+ansB,mxB);
            ansB+=val;
            toMoveB=store[toMoveB][0]-1;
            if(toMoveB==b-1) break;
            kB--;
        }
 
        ll ansS=0;
        ll toMoveS=s-1;
        vector<ll>strAnsS;
        ll stepsS=0;
        ll kS=k;
        ll mxS=0;
        while(kS>0){
            ll val=store[toMoveS][1];
            mxS=max(val*kS+ansS,mxS);
            ansS+=val;
            toMoveS=store[toMoveS][0]-1;
            if(toMoveS==s-1) break;
            kS--;
        }
        if(mxB>mxS) cout<<"Bodya"<<"\n";
        else if(mxB<mxS) cout<<"Sasha"<<"\n";
        else cout<<"Draw"<<"\n";
    }
    return 0;
}