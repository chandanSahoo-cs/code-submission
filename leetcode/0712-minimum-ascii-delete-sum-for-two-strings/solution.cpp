class Solution {
public:

    // int rec(string &s1, string &s2, int i, int j,vector<int>&v1, vector<int>&v2){
    //     int n = s1.size();
    //     int m = s2.size();

    //     if(i==n || j==m){
    //         int sum = 0;

    //         if(i<n){
    //             sum+=v1[n-1]-(i==0?0:v1[i-1]);
    //         }

    //         if(j<m){
    //             sum+=v2[m-1]-(j==0?0:v2[j-1]);
    //         }

    //         return sum;
    //     }

    //     if(dp[i][j]!=-1) return dp[i][j];

    //     int ans = INT_MAX;

    //     if(s1[i]==s2[j]){
    //         ans = min(ans,rec(s1,s2,i+1,j+1,v1,v2));
    //     }

    //     ans = min(ans,s1[i]+rec(s1,s2,i+1,j,v1,v2));
    //     ans = min(ans,s2[j]+rec(s1,s2,i,j+1,v1,v2));

    //     return dp[i][j] = ans;
    // }

    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(),m = s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1));

        dp[n][0] = s2[m-1];
        dp[0][m] = s1[n-1];

        for(int i=n-1;i>=0;i--){
            dp[i][m] = dp[i+1][m]+s1[i];
        }

        for(int j=m-1;j>=0;j--){
            dp[n][j] = dp[n][j+1]+s2[j];
        }

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int ans = INT_MAX;
                
                if(s1[i]==s2[j]){
                    ans = min(ans,dp[i+1][j+1]);
                }

                ans = min(ans,s1[i]+dp[i+1][j]);
                ans = min(ans,s2[j]+dp[i][j+1]);

                dp[i][j] = ans;
            }
        }

        return dp[0][0];
    }
};
