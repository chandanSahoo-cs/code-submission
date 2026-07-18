#define ll long long

class Solution {
public:
    
    ll maximumValue(int n, int s, int m) {
        if(n==1) return s;

        ll k = n/2;
        ll a = s+m;

        ll val = a+(k-1)*(m-1);

        return val;
    }
};
