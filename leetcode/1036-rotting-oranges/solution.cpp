class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2 || grid[i][j]==0){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }

        int cnt=0;

        while(!q.empty()){

            int sz = q.size();
            cnt++;

            while(sz--){
                auto [i,j] = q.front();
                q.pop();

                if(grid[i][j]==0) continue;

                int dr[] = {0,0,-1,1};
                int dc[] = {-1,1,0,0};

                for(int k=0;k<4;k++){
                    int r = i+dr[k];
                    int c = j+dc[k];

                    if(r<0 || r>=n || c<0 || c>=m || vis[r][c] || grid[r][c]==0) continue;
                    vis[r][c]=1;
                    q.push({r,c});

                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0) return -1;
            }
        }

        return cnt-1;
    }
};
