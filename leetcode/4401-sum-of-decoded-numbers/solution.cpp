#define ll long long
const int mod = 1e9+7;

class Solution {
public:
    ll binexp(ll base, ll exp){
        if(exp==1) return base;
        ll ans = 1;

        while(exp){
            if(exp&1){
                ans = (ans*base)%mod;
            }
            base = (base*base)%mod;
            exp>>=1;
        }

        return ans;
    }

    ll compute(ll a){
        ll wid = a%10;
        ll d = a/10;

        ll len = log10(d)+1;

        ll x = d/binexp(10,len-wid);
        ll y = d%binexp(10,len-wid);

        return binexp(x,y);
    }

    int sumDecoded(vector<ll>& nums) {
        ll ans = 0;
        
        for(auto ele:nums){
            ans = (ans+compute(ele))%mod;
        }

        return ans;
    }
};
