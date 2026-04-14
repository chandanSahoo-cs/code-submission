class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2));

        for(int i=n-1;i>=0;i--){
            for(int j=1;j>=0;j--){
                int p = j?-prices[i]+dp[i+1][!j]:prices[i]+dp[i+2][!j];
                int np = dp[i+1][j];

                dp[i][j] = max(p,np);
            }
        }

        return dp[0][1]; 
    }
};
