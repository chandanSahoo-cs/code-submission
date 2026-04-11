class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1);
        dp[0]=0;

        for(int i=1;i<=n;i++){
            int mn = 1e5;
            for(int j=1;j*j<=i;j++){
                mn = min(mn,1+dp[i-j*j]);
            }
            dp[i] = mn;
        }

        return dp[n];
    }
};
