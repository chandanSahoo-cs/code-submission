class Solution {
public:
    int maxProduct(int n) {
        int val1 = -1, val2 = -1;

        while(n){
            int ele = n%10;

            if(ele>=val1){
                val2 = val1;
                val1 = ele;
            }else if(ele>val2){
                val2 = ele;
            }

            n/=10;
        }

        return val1*val2;
    }
};
