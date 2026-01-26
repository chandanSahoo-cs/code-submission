class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<tuple<int,int,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j,0});
                    vis[i][j] = 1;
                }
            }
        }

        int dr[] = {0,0,-1,1};
        int dc[] = {-1,1,0,0};

        while(!q.empty()){
            auto [r,c,l] = q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int row = r+dr[k];
                int col = c+dc[k];

                if(row<0 || row>=n || col<0 || col>=m || vis[row][col]) continue;
                vis[row][col] = 1;
                q.push({row,col,l+1});
                mat[row][col] = l+1;
            }
        }

        return mat;
    }
};
