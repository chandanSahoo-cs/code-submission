class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        int mx = -1e9;

        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                mx = max(mx,grid[i][j]);
            }
        }

        for(int i=0;i<n;i++){
            int curr = grid[i][0];

            for(int j=1;j<m;j++){
                mx = max(mx,grid[i][j]+curr);
                curr = max(curr+grid[i][j],grid[i][j]);
            }
        }

        for(int j=0;j<m;j++){
            int curr = grid[0][j];

            for(int i=1;i<n;i++){
                mx = max(mx,grid[i][j]+curr);
                curr = max(curr+grid[i][j],grid[i][j]);
            }
        }

        return mx;
    }
};
