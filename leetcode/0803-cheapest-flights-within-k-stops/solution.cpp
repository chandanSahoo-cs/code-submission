const int INF = 1e9+7;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);

        for(auto ele:flights){
            adj[ele[0]].push_back({ele[1],ele[2]});
        }

        vector<int>vis(n,INF);
        queue<pair<int,int>>q;

        q.push({src,0});
        vis[src]=0;

        int level = 0;

        while(!q.empty()){
            int sz = q.size();
            if(level-1==k) break;
            level++;

            for(int i=0;i<sz;i++){
                auto [u,c] = q.front();
                q.pop();

                cout<<u<<" "<<c<<"\n";

                for(auto [v,cst]:adj[u]){
                    if(vis[v]>c+cst){
                        vis[v]=c+cst;
                        q.push({v,vis[v]});
                    }
                }
            }
        }

        return vis[dst]==INF?-1:vis[dst];
    }
};
