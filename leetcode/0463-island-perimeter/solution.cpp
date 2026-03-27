class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        int cnt = 0;


        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
                    break;
                }
            }
        }


        int dr[] = {0,0,-1,1};
        int dc[] = {-1,1,0,0};

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int tr = r+dr[k];
                int tc = c+dc[k];

                if(tr<0 || tr>=n || tc<0 || tc>=m || grid[tr][tc]==0) cnt++;
                else{
                    if(!vis[tr][tc]){
                        q.push({tr,tc});
                        vis[tr][tc]=1;
                    }
                }
            }
        }

        return cnt;
    }
};
