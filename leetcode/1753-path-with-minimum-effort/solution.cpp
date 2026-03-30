class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();

        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>>pq;
        
        pq.push({0,0,0});
        dist[0][0]=0;

        int dr[] = {0,0,-1,1};
        int dc[] = {-1,1,0,0};

        while(!pq.empty()){
            auto [d,r,c] = pq.top();
            pq.pop();

            if(dist[r][c]<d) continue;
            
            for(int k=0;k<4;k++){
                int tr = r+dr[k];
                int tc = c+dc[k];

                if(tr<0 || tr>=n || tc<0 || tc>=m) continue;
                int diff = max(d,abs(heights[tr][tc]-heights[r][c]));

                if(diff<dist[tr][tc]){
                    pq.push({diff,tr,tc});
                    dist[tr][tc] = diff;
                }
            }          
        }

        return dist[n-1][m-1];
    }
};
