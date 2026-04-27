class Solution {
public:
    tuple<int,int,int,int> path(int i){
        int left = 0, right = 0, up = 0, down = 0;

        if(i==1){
            left=1,right=1;    
        }else if(i==2){
            up=1, down=1;
        }else if(i==3){
            left=1, down=1;
        }else if(i==4){
            right=1, down=1;
        }else if(i==5){
            left=1, up=1;
        }else{
            right=1, up=1;
        }

        return {left,right,up,down};
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(n==1 && m==1) return true;

        vector<vector<int>>vis(n,vector<int>(m));
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0][0]=1;

        int dr[] = {0,0,-1,1};
        int dc[] = {-1,1,0,0};

        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();

            auto [ol,orr,ou,od] = path(grid[i][j]);

            for(int k=0;k<4;k++){
                int r = i+dr[k];
                int c = j+dc[k];

                if(r<0 || r>=n || c<0 || c>=m || vis[r][c]) continue;

                auto [nl,nr,nu,nd] = path(grid[r][c]);

                if((ol && nr && k==0) || (orr && nl && k==1) || (ou && nd && k==2) || (od && nu && k==3)){
                    if(r==n-1 && c==m-1) return true;
                    q.push({r,c});
                    vis[r][c] = 1;
                }
            }
        }

        return false;    
    }
};
