class Solution {
    int dp[205];
public:
    int minimumTotal(vector<vector<int>>& a) {
        int n = a.size();
        memset(dp,-1,sizeof(dp));

        for(int i=n-1;i>=0;i--){
            int m = a[i].size();
            for(int j=0;j<=m;j++){
                if(j==m) dp[j] = 1e9;
                else if(i==n-1) dp[j] = a[i][j];
                else{
                    int ans = min(dp[j],dp[j+1]);
                    dp[j]= ans+a[i][j];
                }
            }
        }
        return dp[0];    
    }
};
