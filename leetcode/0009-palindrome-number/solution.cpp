class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;

        int tempx = x;
        long long hold=0;
        while(tempx>0){
            hold+=tempx%10;
            hold*=10;
            tempx/=10;
        }
        hold/=10;


        return hold==x;
    }
};
