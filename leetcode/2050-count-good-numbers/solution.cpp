#define ll long long
class Solution {
public:
    ll mod = 1e9+7;
    ll Pow(ll n,ll x,map<ll,ll>&mp){
        ll mod = 1e9+7;
        if(x==0) return 1;
        if(x==1) return n;
        if(mp.find(x)!=mp.end()) return mp[x];
        ll res = Pow(n,x/2,mp)%mod;
        if(x%2!=0){
            return mp[x] = (n%mod*res%mod*res%mod)%mod;
        }
        else{
            return mp[x] = (res%mod*res%mod)%mod;
        }
    }
    int countGoodNumbers(long long n) {
        ll mod = 1e9+7;
        map<ll,ll>mp1,mp2;
        return (int)((Pow(4,n/2,mp1)*Pow(5,n-n/2,mp2))%mod);
    }
};
