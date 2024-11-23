class Solution {
#define ll long long
public:
    const int M = 1337;
    int superPow(int a, vector<int>& b) {
        ll n = b.size();
        auto binExp = [&](ll a,ll b,ll m){
            ll ans=1;
            while(b){
                if(b&1) ans=(ans*1LL*a)%m;
                b>>=1;
                a=(a*a)%m;
            }
            return ans;
        };

        ll phiM = 1140;
        ll newB=0;
        ll pw=0;

        for(ll i=n-1;i>=0;i--){
            b[i]=b[i]*binExp(10,pw,phiM);
            pw++;
            newB+=b[i];
        }

        return (int)binExp(a,newB,1337);
    }
};
