class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<vector<int>>>dist(n,vector<vector<int>>(m,vector<int>(k+1,0)));
        queue<tuple<int,int,int>>q;

        q.push({0,0,k}); 
        dist[0][0][k] = 1;

        int dr[] = {0,0,-1,1};
        int dc[] = {-1,1,0,0};

        int steps = 0;
        while(!q.empty()){
            
            int sz = q.size();

            while(sz--){
                auto [i,j,nk] = q.front();
                q.pop();

                if(i==n-1 && j==m-1) return steps;

                for(int l=0;l<4;l++){
                    int r = i+dr[l];
                    int c = j+dc[l];

                    if(r<0 || r>=n || c<0 || c>=m) continue;
                    
                    if(!grid[r][c]){
                        if(!dist[r][c][nk]){
                            dist[r][c][nk] = 1;
                            q.push({r,c,nk});
                        }
                    }else if(grid[r][c] && nk>0){
                        if(!dist[r][c][nk-1]){
                            dist[r][c][nk-1] = 1;
                            q.push({r,c,nk-1});
                        }
                    }
                } 
            }
            steps++;
        }

        return -1;
    }
};
