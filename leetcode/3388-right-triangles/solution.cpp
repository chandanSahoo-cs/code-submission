class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>row(n);
        vector<int>col(m);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    row[i]++;
                    col[j]++;
                }
            }
        }

        long long ans = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    if(row[i] && col[j]){
                        ans+=(row[i]-1)*(col[j]-1);
                    }
                }
            }
        }

        return ans;
    }
};
