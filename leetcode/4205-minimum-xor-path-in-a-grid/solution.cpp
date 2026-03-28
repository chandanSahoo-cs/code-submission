bitset<1024>dp[1005][1005];
bool vis[1005][1005];
class Solution {
public:

    bitset<1024> rec(vector<vector<int>>&grid, int i, int j){
        int n = grid.size(), m = grid[0].size();
        bitset<1024>res;
        
        if(i==n || j==m) return res;


        if(i==n-1 && j==m-1){
            res[grid[i][j]]=1;
            return res;
        }

        if(vis[i][j]) return dp[i][j];
        vis[i][j] = true;

        bitset<1024> down = rec(grid,i+1,j);
        bitset<1024> right = rec(grid,i,j+1);
        
        for(int k=0;k<1024;k++){
            if(down[k]){
                res[k^grid[i][j]]=1;
            }
            if(right[k]){
                res[k^grid[i][j]]=1;
            }
        }
        
        return dp[i][j]=res;
    }
    
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j].reset();
                vis[i][j]=false;
            }
        }

        bitset<1024>res = rec(grid,0,0);
        
        for(int k=0;k<1024;k++){
            if(res[k]) return k;
        }

        return -1;
    }
};
