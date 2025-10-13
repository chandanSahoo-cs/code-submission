class Solution {
    int dp[105][105];
public:
    int rec(vector<vector<int>>&a, int i, int j){
        int n = a.size();
        int m = a[0].size();

        if(dp[i][j]!=-1) return dp[i][j];

        if(i==n || j==m || a[i][j]) return 0;
        if(i==n-1 && j==m-1) return 1;

        int ans = rec(a,i+1,j)+rec(a,i,j+1);

        return dp[i][j] = ans;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        memset(dp,-1,sizeof(dp));
        return rec(a,0,0);    
    }
};
