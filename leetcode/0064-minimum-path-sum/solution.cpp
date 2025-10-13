class Solution {
public:
    int minPathSum(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();

        int dp[205];
        for(int i=n;i>=0;i--){
            for(int j=m;j>=0;j--){
                if(i==n || j==m){
                    dp[j]=1e9;
                }else if(i==n-1){
                    if(j==m-1){
                        dp[j] = a[i][j];
                    }else{
                        dp[j] = a[i][j]+dp[j+1]; 
                    }
                }else{
                    int ans = min(dp[j+1],dp[j]);
                    dp[j]=ans+a[i][j];
                }
            }
        }

        return dp[0];
    }
};
