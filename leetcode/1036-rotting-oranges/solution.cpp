class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m));
        queue<vector<int>>q;

        int time = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){ 
                    q.push({i,j,0});
                    vis[i][j]=1;
                }
            }
        }

        while(!q.empty()){
            vector<int>ele = q.front();
            int r = ele[0];
            int c = ele[1];
            int t = ele[2];

            time = max(time,t);

            q.pop();

            vector<int>dr = {0,1,0,-1};
            vector<int>dc = {1,0,-1,0};

            for(int k=0;k<4;k++){
                int nr = r+dr[k];
                int nc = c+dc[k];

                if(nr>=n || nr<0 || nc>=m || nc<0 || vis[nr][nc] || grid[nr][nc]==0) continue;
                q.push({nr,nc,t+1});
                vis[nr][nc]=1;
                if(grid[nr][nc]==1) grid[nr][nc] = 2;
            }

            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cout<<grid[i][j]<<" ";
                }
                cout<<"\n";
            }
            cout<<"\n";
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // cout
                if(grid[i][j]==1) return -1;
            }
        }



        return time;
    }
};
