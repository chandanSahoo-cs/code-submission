class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m =grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m));
        queue<pair<int,int>>q;

        int tot = 0;

        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(grid[i][j]==1){
                        vis[i][j] = 1;
                        q.push({i,j});
                        cnt++;
                    }
                }
                tot+=grid[i][j];
            }
        }

        while(!q.empty()){
            pair<int,int>pr = q.front();
            q.pop();

            int f = pr.first;
            int s = pr.second;

            int dr[] = {0,0,-1,1};
            int dc[] = {-1,1,0,0};

            for(int k=0;k<4;k++){
                int nr = f+dr[k];
                int nc = s+dc[k];

                if(nr>=n || nr<0 || nc>=m || nc<0 || vis[nr][nc] || !grid[nr][nc]) continue;
                q.push({nr,nc});
                vis[nr][nc]=1;
                cnt++;
            }
        }

        return tot-cnt;
    }
};
