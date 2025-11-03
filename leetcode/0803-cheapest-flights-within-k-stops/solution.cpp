class Solution {
    const int INF = 1e8;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);

        for(auto ele:flights){
            adj[ele[0]].push_back({ele[1],ele[2]});
        }

        queue<vector<int>>q;

        vector<int>dist(n,INF);

        q.push({k,0,src});
        dist[src]=0;

        while(!q.empty()){
            vector<int>v = q.front();
            q.pop();

            int currK = v[0];
            int cost = v[1];
            int node = v[2];

            for(auto ele:adj[node]){
                if(currK>=0 && dist[ele.first]>ele.second+cost){
                    dist[ele.first] = ele.second+cost;
                    q.push({currK-1,ele.second+cost,ele.first});
                }
            }
        }


        return dist[dst]==INF?-1:dist[dst];
    }
};
