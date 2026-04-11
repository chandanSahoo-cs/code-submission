class Solution {
public:
    int integerBreak(int n) {
        vector<int>dp(n+1);
        dp[0] = 1;

        for(int i=1;i<=n;i++){
            int mx = 1;
            for(int j=1;j<=i;j++){
                mx = max(mx,j*dp[i-j]);
            }
            dp[i] = mx;
        }

        int mx = 1;
        for(int i=1;i<n;i++){
            mx = max(mx,dp[i]*dp[n-i]);
        }

        return mx;
    }
};
