class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &ele:edges){
            adj[ele[0]].push_back({ele[1],ele[2]});
        }

        vector<vector<int>>dist(n,vector<int>(k,INT_MAX));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>>pq;

        pq.push({0,0,k-1});
        dist[0][k-1] = 0;

        while(!pq.empty()){
            auto[w,u,currK] = pq.top();
            pq.pop();

            if(dist[u][currK]<w) continue;
            if(u==n-1) return w;

            for(auto [v,weigh]:adj[u]){
                int tempK = labels[u]==labels[v]?currK-1:k-1;
                if(tempK<0) continue;
                
                if(weigh+w<dist[v][tempK]){
                    dist[v][tempK] = weigh+w;
                    pq.push({dist[v][tempK],v,tempK});
                }
            }
        }

        return -1;
    }
};
