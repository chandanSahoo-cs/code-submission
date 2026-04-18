class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int>a(n+2,1);

        for(int i=0;i<n;i++){
            a[i+1] = nums[i];
        }

        vector<vector<int>>dp(n+2,vector<int>(n+2));

        for(int l=n+1;l>=0;l--){
            for(int r=0;r<=n+1;r++){
                if(r-l<=1) continue;
                int ans = 0;
                
                for(int i=l+1;i<r;i++){
                    ans = max(ans,a[l]*a[i]*a[r]+dp[l][i]+dp[i][r]);
                }
                dp[l][r] = ans;
            }
        }

        return dp[0][n+1];
    }
};
