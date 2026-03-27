class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();

        vector<vector<int>>vis(n,vector<int>(m));
        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && board[i][j]=='O'){
                    q.push({i,j});
                    vis[i][j]=1;
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

                if(tr<0 || tr>=n || tc<0 || tc>=m || board[tr][tc]!='O' || vis[tr][tc]) continue;
                vis[tr][tc]=1;
                q.push({tr,tc});
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    board[i][j]='X';
                }
            }
        }

        return;
    }
};
