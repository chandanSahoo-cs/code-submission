#define ll long long

class Solution {
public:
    ll countCommas(ll n) {
        ll buff = 1000;

        ll cnt = 0;
        ll tn = n;

        while(tn-buff>=0){
            cnt+=tn-buff+1;
            buff*=1000;
        }

        return cnt;
    }
};

/*
1000000
 999001
*/
