#define ll long long
const int mod = 1e9+7;

class Solution {
public:
    pair<ll,ll>dp[20][20];
    bool vis[20][20];

    pair<ll,ll> rec(vector<vector<int>>&grid,int i, int j){
        int n = grid.size(), m = grid[0].size();

        if(i>=n || j>=m){
            return {LLONG_MIN,LLONG_MAX};
        }

        if(i==n-1 && j==m-1){
            return {grid[i][j],grid[i][j]};
        }

        if(vis[i][j]) return dp[i][j];

        auto [dmax,dmin] = rec(grid,i+1,j);
        auto [lmax,lmin] = rec(grid,i,j+1);

        ll mx = max(dmax,lmax);
        ll mn = min(dmin,lmin);

        vis[i][j]=true;

        if(grid[i][j]<0){
            return dp[i][j]={mn*grid[i][j],mx*grid[i][j]};
        }

        return dp[i][j]={mx*grid[i][j],mn*grid[i][j]};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));

        auto [mx,mn] = rec(grid,0,0);

        return mx<0?-1:(mx)%mod;
    }
};
