class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();

        queue<tuple<int,int,int>>q;
        vector<vector<vector<int>>>vis(n,vector<vector<int>>(m,vector<int>(health+1)));

        q.push({0,0,health-grid[0][0]});
        vis[0][0][health-grid[0][0]]=1;

        int dr[] = {0,0,-1,1};
        int dc[] = {-1,1,0,0};

        while(!q.empty()){
            auto [x,y,h] = q.front();
            q.pop();

            if(x==n-1 && y==m-1) return true;

            for(int k=0;k<4;k++){
                int r = x+dr[k];
                int c = y+dc[k];

                if(r<0 || r>=n || c<0 || c>=m || h-grid[r][c]<=0 || vis[r][c][h-grid[r][c]]) continue;

                q.push({r,c,h-grid[r][c]});
                vis[r][c][h-grid[r][c]]=1;
            }
        }

        return false;
    }
};
