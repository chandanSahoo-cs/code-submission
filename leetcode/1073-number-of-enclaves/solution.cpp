class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && (i==0 || j==0 || i==n-1 || j==m-1)){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }

        int dr[] = {0,0,-1,1};
        int dc[] = {-1,1,0,0};

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int row = r+dr[k];
                int col = c+dc[k];

                if(row<0 || row>=n || col<0 || col>=m || vis[row][col] || !grid[row][col]) continue;

                vis[row][col]=1;
                q.push({row,col});
            }
        }

        int tot = 0;
        int cnt = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                tot+=grid[i][j];
                cnt+=vis[i][j];
            }
        }

        return tot-cnt;
    }
};
