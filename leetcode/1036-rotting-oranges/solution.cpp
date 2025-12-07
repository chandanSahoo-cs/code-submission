class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<int>dr = {0,0,-1,1};
        vector<int>dc = {-1,1,0,0};

        queue<vector<int>>q;

        vector<vector<int>>vis(n,vector<int>(m,-1));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j,0});
                }else if(grid[i][j]==0){
                    vis[i][j]=0;
                }
            }
        }

        int cnt=0;

        while(!q.empty()){
            auto pr = q.front();
            q.pop();

            int cost = pr[2];
            int f = pr[0];
            int s = pr[1];
            if(vis[f][s]!=-1) continue;

            vis[f][s]=cost;

            for(int i=0;i<4;i++){
                int r = f+dr[i];
                int c = s+dc[i];

                if(r<0 || r>=n || c<0 || c>=m || vis[r][c]!=-1 || grid[r][c]!=1) continue;
                q.push({r,c,cost+1});
            }
        }

        int mx = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==-1) return -1;
                mx = max(mx,vis[i][j]);
            }
        }

        return mx;
    }
};
