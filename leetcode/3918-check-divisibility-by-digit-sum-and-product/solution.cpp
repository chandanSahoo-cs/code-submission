class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int prod = 1;
        int tn = n;
        
        while(n){
            int val = n%10;
            sum+=val;
            prod*=val;
            n/=10;
        }
        
        return !(tn%(sum+prod));
    }
};
