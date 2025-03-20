class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN){
            if(divisor==-1){
                return INT_MAX;
            }
            else if(divisor==1) return INT_MIN;
        }
        else if (dividend==INT_MAX){
            if(divisor==-1) return -INT_MAX;
            else if (divisor==1) return INT_MAX;
        }

        bool sign = (dividend<0)^(divisor<0);
        long long a = dividend;
        long long b = divisor;
        a = abs(a);
        b = abs(b);
        cout<<a<<"\n";
        int ans=0;
        while(a>=b){
            long long temp = b;
            int i=0;
            while(a>=(temp<<i)){
                i++;
            }
            a-=(temp<<(i-1));
            ans+=(1<<(i-1));
        }

        cout<<ans<<"\n";

        return sign ? -ans : ans;
    }
};
