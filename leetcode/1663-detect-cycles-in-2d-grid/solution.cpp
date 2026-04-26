class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        int dr[] = {0,0,-1,1};
        int dc[] = {-1,1,0,0};

        vector<vector<int>>vis(n,vector<int>(m));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]) continue;

                queue<tuple<int,int,int,int>>q;
                q.push({i,j,-1,-1});
                vis[i][j] = 1;

                while(!q.empty()){
                    auto [i,j,previ,prevj] = q.front();
                    q.pop();

                    for(int k=0;k<4;k++){
                        int r = i+dr[k];
                        int c = j+dc[k];

                        if(r<0 || r>=n || c<0 || c>=m || (r==previ && c==prevj) || grid[r][c]!=grid[i][j]) continue;
                        if(vis[r][c]) return true;
                        vis[r][c] = 1;
                        q.push({r,c,i,j});
                    }
                }
            }
        }

        return false;
    }
};
