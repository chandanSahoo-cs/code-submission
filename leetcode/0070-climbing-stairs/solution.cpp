class Solution {
public:
    // int dp[50];

    // int rec(int n, int i){
        
    //     if(i>n) return 0;
    //     if(i==n) return 1;

    //     if(dp[i]!=-1) return dp[i];

    //     int ans = rec(n,i+1)+rec(n,i+2);

    //     return dp[i] = ans;
    // }

    int climbStairs(int n) {
        vector<int>dp(n+2);
        dp[n]=1;

        for(int i=n-1;i>=0;i--){
            dp[i] = dp[i+1]+dp[i+2];
        }

        return dp[0];
    }
};
