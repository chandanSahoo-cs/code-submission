const int mod = 1e9+7;
#define ll long long
class Solution {
public:
    int numOfWays(int n) {
        ll distinct = 6, same = 6;

        for(int i=1;i<n;i++){
            ll d = ((2*distinct)%mod + (2*same)%mod)%mod;
            ll s = ((3*same)%mod + (2*distinct)%mod)%mod;

            distinct = d;
            same = s;
        }

        return (distinct+same)%mod;
    }
};
