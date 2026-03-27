class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m));

        bool flag = false;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 || grid[i][j]==2) flag=true;
                if(grid[i][j]==2){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }

        if(!flag) return 0;

        int dr[] = {0,0,-1,1};
        int dc[] = {-1,1,0,0};

        int level = 0;

        while(!q.empty()){
            int sz = q.size();
            level++;

            for(int i=0;i<sz;i++){
                auto [r,c] = q.front();
                q.pop();

                for(int k=0;k<4;k++){
                    int tr = r+dr[k];
                    int tc = c+dc[k];

                    if(tr<0 || tr>=n || tc<0 || tc>=m || !grid[tr][tc] || vis[tr][tc]) continue;
                    q.push({tr,tc});
                    vis[tr][tc]=1;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]) return -1;
            }
        }

        return level-1;
    }
};
