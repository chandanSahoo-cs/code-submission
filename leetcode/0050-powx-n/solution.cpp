class Solution {
public:
    double ans(double x, int n){
        if(n==0) return 1;
        if(n==1) return x;
        double p = ans(x,n/2);
        if(n%2==0){
            return p*p;
        }
        else return x*p*p;

        return 1.00;
    }

    double myPow(double x, int n) {
        map<long long,double>mp;
        if(n<0) return 1/ans(x,n);
        else return ans(x,n);
    }
};
