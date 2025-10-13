class Solution {
int dp[105][105];
public:

    int rec(int n, int m, int i, int j){
        if(i==n || j==m) return 0;
        if(i==n-1 && j==m-1) return 1;

        if(dp[i][j]!=-1) return dp[i][j];

        int ans = rec(n,m,i+1,j)+rec(n,m,i,j+1);

        return dp[i][j] = ans;
    }

    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return rec(n,m,0,0);
    }
};
