class Solution {
    int dp[50];
    int frst=0,scnd=0;
    
public:
    int climbStairs(int n) {
        for(int i=n;i>=0;i--){
            if(i==n){
                frst=1;
            }else{
                int temp = frst;
                frst+=scnd;
                scnd=temp;
            }
        }

        return frst;
    }
};
