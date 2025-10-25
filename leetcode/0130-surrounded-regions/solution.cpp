class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>>vis(n,vector<int>(m));
        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            for(int  j=0;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && board[i][j]=='O'){
                    vis[i][j]=1;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            pair<int,int>pr = q.front();
            q.pop();
            int f = pr.first;
            int s = pr.second;

            int dr[] = {0,0,-1,1};
            int dc[] = {-1,1,0,0};

            for(int k=0;k<4;k++){
                int nr = f+dr[k];
                int nc = s+dc[k];

                if(nr<0 || nr>=n || nc<0 || nc>=m || vis[nr][nc] || board[nr][nc]=='X') continue;
                vis[nr][nc] = 1;
                q.push({nr,nc});
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    board[i][j]='X';
                }
            }
        }

        return ;
    }
};
