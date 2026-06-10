class Solution {
public:
    const int mod = 1e9+7;
    vector<vector<vector<int>>>dp;
    int rec(vector<vector<int>>&grid, int k, int i, int j, int sum){
        int n = grid.size(), m = grid[0].size();

        if(i>=n || j>=m) return 0;
        int md = (sum+grid[i][j])%k;

        if(i==n-1 && j==m-1){
            if(md) return 0;
            else return 1;
        }
        
        if(dp[i][j][md]!=-1) return dp[i][j][md];

        int res = (rec(grid,k,i+1,j,md)+rec(grid,k,i,j+1,md))%mod;

        return dp[i][j][md] = res;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        dp.resize(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));

        return rec(grid,k,0,0,0);
    }
};
