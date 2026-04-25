class Solution {
public:
    bool validDigit(int n, int x) {

        int lst = -1;
        int cnt = 0;

        while(n){
            if(n%10==x) cnt++;
            lst = n%10;
            n/=10;
        }

        return lst!=x && cnt;
    }
};
