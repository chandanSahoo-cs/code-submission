#define ll long long

class Solution {
public:
    int kthDigit(ll k) {
        if(k<=9) return k;

        ll s = 1;
        ll d = 1;
        ll prev = 0;

        while(prev+s*9*d<k){
            prev+=(s*9*d);
            d++;
            s*=10;
        }

        k-=prev;
        k--;

        ll num = k/d;
        ll pos = k%d;

        ll ans = 1;
        for(ll i=0;i<d-1;i++){
            ans*=10;
        }

        ans+=num;
        
        ll b = ans/10;

        if(b&1){
            ans = b*10+(9-ans%10);
        }

        return to_string(ans)[pos]-'0';
    }
};
