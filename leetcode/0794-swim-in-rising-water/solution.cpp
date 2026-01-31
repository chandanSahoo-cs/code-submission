const int INF = 1e9+7;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>>dist(n,vector<int>(n,INF));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>>pq;

        pq.push({grid[0][0],0,0});
        dist[0][0] = grid[0][0];

        int dr[] = {0,0,-1,1};
        int dc[] = {-1,1,0,0};

        while(!pq.empty()){
            auto [w,i,j] = pq.top();
            pq.pop();

            if(dist[i][j]<w) continue;

            for(int k=0;k<4;k++){
                int r = i+dr[k];
                int c = j+dc[k];

                if(r<0 || r>=n || c<0 || c>=n) continue;

                if(dist[r][c]>max(w,grid[r][c])){
                    dist[r][c] = max(w,grid[r][c]);
                    pq.push({dist[r][c],r,c});
                }
            } 
        }

        return dist[n-1][n-1];
    }
};
