class Solution {
public:
    vector<int>ans;
    bool dfs(vector<vector<int>>&adj, vector<int>&vis, vector<int>&pathVis, int curr){
        if(pathVis[curr]) return true;
        if(vis[curr]) return false;

        pathVis[curr] = vis[curr] = 1;

        bool flag = false;
        for(auto v:adj[curr]){
            flag |= dfs(adj,vis,pathVis,v);
            if(flag) break;
        }

        if(!flag){
            ans.push_back(curr);
            pathVis[curr] = 0;
        }

        return flag;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int>vis(n),pathVis(n);

        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            dfs(graph,vis,pathVis,i);
        }

        sort(ans.begin(),ans.end());

        return ans;
    }
};
