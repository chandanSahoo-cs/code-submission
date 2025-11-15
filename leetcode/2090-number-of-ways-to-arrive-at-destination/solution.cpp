
class Solution {
    const int MOD=1e9+7;
    const long long INF=1e12;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        if(n==1) return 1;
        vector<vector<pair<int,int>>> adj(n);

        for(auto ele:roads){
            adj[ele[0]].push_back({ele[1],ele[2]});
            adj[ele[1]].push_back({ele[0],ele[2]});          
        }

        priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>>pq;
        vector<long long>dist(n,INF);
        vector<long long>ways(n,0);

        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;

        while(!pq.empty()){
            auto node = pq.top();
            long long d = node[0];
            int u = node[1];
            pq.pop();

            if(d>dist[u]) continue;

            for(auto ele:adj[u]){
                int v = ele.first;
                int cost = ele.second;

                if(cost+d==dist[v]){
                    ways[v]=(ways[v]+ways[u])%MOD;
                }else if(cost+d<dist[v]){
                    dist[v]=cost+d;
                    ways[v]=ways[u];
                    pq.push({dist[v],v});
                }
            }
        }

        return ways[n-1];
    }
};
