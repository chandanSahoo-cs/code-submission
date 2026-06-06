class Solution {
public:

    bool consecutiveSetBits(int n) {

        int cnt = 0;
        int pair = 0;

        while(n){
            if(n&1) cnt++;
            else cnt=0;

            if(cnt>=2) pair++;
            n>>=1;
        }

        if(pair==1) return true;

        return false;        
    }
};
