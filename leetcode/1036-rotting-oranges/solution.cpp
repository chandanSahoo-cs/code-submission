class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>mark(n,vector<int>(m));

        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2 || grid[i][j]==0){
                    q.push({i,j});
                    mark[i][j]=1;
                }
            }
        }

        int level = 0;

        while(!q.empty()){
            int sz = q.size();
            level++;
            for(int i=0;i<sz;i++){
                auto [r,c] = q.front();
                q.pop();
                if(grid[r][c]==0) continue;

                int dr[] = {0,0,1,-1};
                int dc[] = {-1,1,0,0};

                for(int k=0;k<4;k++){
                    int row = r+dr[k];
                    int col = c+dc[k];

                    if(row<0 || row>=n || col<0 || col>=m || grid[row][col]==0 || mark[row][col]) continue;
                    mark[row][col] = 1;
                    q.push({row,col});
                } 
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !mark[i][j]) return -1;
            }
        }

        return level-1;
    }
};
