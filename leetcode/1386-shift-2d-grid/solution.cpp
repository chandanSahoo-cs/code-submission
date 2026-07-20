class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        int t = n*m;
        k = k%t;

        vector<vector<int>>ans(n,vector<int>(m));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int idx = i*m+j;
                int nIdx = (idx+k)%t;

                int r = nIdx/m;
                int c = nIdx%m;


                ans[r][c] = grid[i][j];
            }
        }

        return ans;
    }
};


