class Solution {
    #define ll long long
public:
    int arrangeCoins(int n) {
        ll s=1,e=n;
        while(s<=e){
            ll m=s+(e-s)/2;
            if((m*(m+1))/2==n) return m;
            else if((m*(m+1))/2>n) e=m-1;
            else s=m+1;
        }
        return e;
    }
};
