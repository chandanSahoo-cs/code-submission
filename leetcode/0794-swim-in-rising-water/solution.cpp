class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>>pq;

        pq.push({grid[0][0],0,0});
        dist[0][0]=grid[0][0];

        int dr[] = {0,0,-1,1};
        int dc[] = {-1,1,0,0};

        while(!pq.empty()){
            auto [w,r,c] = pq.top();
            pq.pop();

            if(dist[r][c]<w) continue;

            for(int k=0;k<4;k++){
                int tr = r+dr[k];
                int tc = c+dc[k];

                if(tr<0 || tr>=n || tc<0 || tc>=n || dist[tr][tc]<=max(w,grid[tr][tc])) continue;
                dist[tr][tc] = max(w,grid[tr][tc]);
                pq.push({dist[tr][tc],tr,tc});
            }
        }

        return dist[n-1][n-1];
    }
};
