class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& pf) {
        int n = pf.size();

        vector<vector<pair<int,int>>>adj(n);

        for(auto &ele:edges){
            adj[ele[0]].push_back({ele[1],ele[2]});
            adj[ele[1]].push_back({ele[0],ele[2]});
        }

        // cost,time,u

        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>>pq;
        vector<vector<int>>dist(n,vector<int>(maxTime+1,INT_MAX));

        pq.push({pf[0],0,0});
        dist[0][0]=pf[0];

        while(!pq.empty()){
            auto [cost,time,u] = pq.top();
            pq.pop();

            if(u==n-1) return cost;
            if(dist[u][time]<cost) continue;

            for(auto &[v,t]:adj[u]){
                if(time+t<=maxTime){
                    if(pf[v]+cost<dist[v][time+t]){
                        dist[v][time+t] = pf[v]+cost;
                        pq.push({pf[v]+cost,time+t,v});
                    }
                }
            }
        }

        return -1;
    }
};
