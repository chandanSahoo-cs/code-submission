class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();

        vector<int>dp(m);
        for(int i=n-1;i>=0;i--){
            vector<int>temp(m);
            for(int j=0;j<m;j++){
                if(i==n-1){
                    temp[j] = a[i][j];
                }else{
                    int ans = 1e9;
                    ans = min(ans,dp[j]);
                    if(j-1>=0){
                        ans = min(ans,dp[j-1]);
                    }

                    if(j+1<m){
                        ans = min(ans,dp[j+1]);
                    }

                    temp[j] = ans+a[i][j];
                }
            }
            dp = temp;
        }

        int ans = 1e9;

        for(int i=0;i<m;i++){
            ans = min(ans,dp[i]);
        }

        return ans;
    }
};
