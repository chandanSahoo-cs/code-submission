class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<vector<pair<int,int>>>adj(n);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj[i].push_back({j,dist});
                adj[j].push_back({i,dist});
            }
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        vector<int>vis(n,0);

        pq.push({0,0});
        int cost = 0;

        while(!pq.empty()){
            auto [w,u] = pq.top();
            pq.pop();

            if(vis[u]) continue;
            vis[u]=1;
            cost+=w;

            for(auto [v,weigh]:adj[u]){
                if(!vis[v]){
                    pq.push({weigh,v});
                }
            }
        }

        return cost;
    }
};
