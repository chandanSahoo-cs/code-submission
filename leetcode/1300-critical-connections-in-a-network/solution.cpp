class Solution {
public:
    int timer = 0;

    void dfs(vector<vector<int>>&adj, vector<int>&vis, vector<int>&tin, vector<int>&low, int u, int par, vector<vector<int>>&ans){
        vis[u]=1;
        tin[u]=low[u]=timer++;

        for(auto v:adj[u]){
            if(v==par) continue;

            if(!vis[v]){
                dfs(adj,vis,tin,low,v,u,ans);
                low[u] = min(low[u],low[v]);
                if(low[v]>tin[u]){
                    ans.push_back({v,u});
                }
            }else{
                low[u] = min(low[u],low[v]);
            }
        }

        return;
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);

        for(auto connection:connections){
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }

        vector<int>vis(n),low(n),tin(n);

        vector<vector<int>>ans;

        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            dfs(adj,vis,tin,low,i,-1,ans);
        }

        return ans;
    }
};
