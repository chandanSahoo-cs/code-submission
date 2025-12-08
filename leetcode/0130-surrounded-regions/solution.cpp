class Solution {
public:
    bool boundary(int i, int j, int n,int m){
        if(i==0 || i==n-1 || j==0 || j==m-1) return true;
        return false;
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        queue<pair<int,int>>q;

        vector<int>dr = {-1,1,0,0};
        vector<int>dc = {0,0,-1,1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(boundary(i,j,n,m) && board[i][j]=='O'){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;

            if(vis[i][j]!=0) continue;

            if(board[i][j]=='X'){
                vis[i][j]=1;
            }else vis[i][j]=2;

            for(int k=0;k<4;k++){
                int r = i+dr[k];
                int c = j+dc[k];

                if(r<0 || r>=n || c<0 || c>=m) continue;
                if(board[r][c]=='X') continue;
                q.push({r,c});
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=2){
                    board[i][j]='X';
                }
            }
        }

        return;    
    }
};
