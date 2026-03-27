class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m));

        int mx = 0;

        queue<pair<int,int>>q;
        int dr[] = {0,0,-1,1};
        int dc[] = {-1,1,0,0};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    
                    q.push({i,j});
                    vis[i][j]=1;


                    int cnt = 1;

                    while(!q.empty()){
                        auto [r,c] = q.front();
                        q.pop();

                        for(int k=0;k<4;k++){
                            int tr = r+dr[k];
                            int tc = c+dc[k];

                            if(tr<0 || tr>=n || tc<0 || tc>=m || !grid[tr][tc] || vis[tr][tc]) continue;
                            cnt++;


                            q.push({tr,tc});
                            vis[tr][tc]=1;
                        }
                    }
                    mx = max(mx,cnt);
                }
            }
        }

        return mx;
    }
};
