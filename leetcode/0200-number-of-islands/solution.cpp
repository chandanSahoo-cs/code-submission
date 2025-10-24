class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m));   

        int cnt = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] || grid[i][j]=='0') continue;
                vis[i][j] = 1;
                cnt++;
                q.push({i,j});

                while(!q.empty()){
                    pair<int,int>pr = q.front();
                    int r = pr.first;
                    int c = pr.second;
                    q.pop();
                    
                    
                    if(c+1<m && grid[r][c+1]=='1' && !vis[r][c+1]) {
                        q.push({r,c+1});
                        vis[r][c+1]=1;
                    }

                    if(r+1<n && grid[r+1][c]=='1' && !vis[r+1][c]) {
                        q.push({r+1,c});
                        vis[r+1][c]=1;
                    }


                    if(c-1>=0 && grid[r][c-1]=='1' && !vis[r][c-1]){ 
                        q.push({r,c-1});
                        vis[r][c-1]=1;
                    }

                    if(r-1>=0 && grid[r-1][c]=='1' && !vis[r-1][c]){ 
                        q.push({r-1,c});
                        vis[r-1][c]=1;
                    }
                }
            }
        }


        return cnt;
    }
};
