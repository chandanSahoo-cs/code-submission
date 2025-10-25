class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>>vis(n,vector<int>(m));
        queue<vector<int>>q;

        int level=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j,0});
                    vis[i][j]=1;
                }
            }
        }

        while(!q.empty()){
            vector<int>pr = q.front();
            q.pop();

            int f = pr[0];
            int s = pr[1];
            int l = pr[2];

            vector<int>dr = {0,0,-1,1};
            vector<int>dc = {-1,1,0,0};

            for(int k=0;k<4;k++){
                int nr = f+dr[k];
                int nc = s+dc[k];

                if(nr>=n || nr<0 || nc>=m || nc<0 || vis[nr][nc]) continue;

                mat[nr][nc] = l+1;
                q.push({nr,nc,l+1});
                vis[nr][nc]=1;
            }
        }

        return mat;
    }
};
