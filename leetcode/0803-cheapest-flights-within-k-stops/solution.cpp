const int INF = 1e9+7;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);

        for(auto ele:flights){
            adj[ele[0]].push_back({ele[1],ele[2]});
        }

        vector<int>vis(n,INF);
        queue<tuple<int,int,int>>q;

        q.push({0,0,src});
        vis[src] = 0;

        while(!q.empty()){
            auto [currK,price,from] = q.front();
            q.pop();

            if(currK>k) continue;


            for(auto [v,p]:adj[from]){
                if(vis[v]>p+price){
                    q.push({currK+1,p+price,v});
                    vis[v]=p+price;
                }
            }
        }

        return vis[dst]==INF?-1:vis[dst];
    }
};
