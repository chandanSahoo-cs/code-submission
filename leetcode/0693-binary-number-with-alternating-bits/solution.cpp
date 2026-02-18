class Solution {
public:
    bool hasAlternatingBits(int n) {
        int check = !(n&1);
        n>>=1;

        while(n){
            if((n&1)==check){
                check=!check;
            }else return false;
            n>>=1;
        }

        return true;
    }
};
