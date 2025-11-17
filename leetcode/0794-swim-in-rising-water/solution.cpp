class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>>pq;

        vector<vector<int>>mark(n,vector<int>(n,1e8));
        mark[0][0]=grid[0][0];

        pq.push({0,0,grid[0][0]});

        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();

            int i = node[0];
            int j = node[1];
            int lev = node[2];

            int dr[] = {0,0,-1,1};
            int dc[] = {-1,1,0,0};

            for(int k=0;k<4;k++){
                int nr = i+dr[k];
                int nc = j+dc[k];

                if(nr<0 || nr>=n || nc<0 || nc>=n) continue;

                if(mark[nr][nc]>lev){
                    mark[nr][nc]=lev;
                    pq.push({nr,nc,max(lev,grid[nr][nc])});
                }
            }
        }

        return max(mark[n-1][n-1],grid[n-1][n-1]);
    }
};
