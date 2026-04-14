class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();

        vector<int>curr(m+1,1e9);
        vector<int>next(m+1,1e9);
        
        curr[m-1]=grid[n-1][m-1];

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1) continue;

                curr[j]= grid[i][j]+min(next[j],curr[j+1]);
            }
            next = curr;
        }

        return next[0];
    }
};
