class Solution {
public:

    bool checkGoodInteger(int n) {
        int sum = 0, sqrSum = 0;

        while(n){
            int dig = n%10;
            sum+=dig;
            sqrSum+=dig*dig;
            n/=10;
        }    

        return sqrSum-sum>=50;
    }
};
