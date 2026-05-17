#define ll long long
class Solution {
public:

    ll binExp(int base, int exp){

        ll ans = 1;

        while(exp){

            if(exp&1){
                ans = ans*1LL*base;
            }

            base = base*1LL*base;

            exp>>=1;
        }

        return ans;
    }
    
    int countKthRoots(int l, int r, int k) {

        if(k==1) return r-l+1;
        
        ll i = 0;

        int cnt = 0;
        while(binExp(i,k)<=r){
            if(binExp(i,k)>=l) cnt++;
            i++;
        }

        return cnt;
    }
};
