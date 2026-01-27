/*Personal note: Meine yeh mark krdiya ki yeh node visited hai, but sath hi sath meine yeh unmark kridya ki woh cycle ka part nhi (agar hai toh)*/
class Solution {
public:
    bool dfs(vector<vector<int>>&adj, vector<int>&vis, vector<int>&pathVis, vector<int>&ans, int curr){
        if(pathVis[curr]) return true;
        if(vis[curr]) return false;

        vis[curr]=1;
        pathVis[curr]=1;

        bool flag = false;
        for(auto ele:adj[curr]){
            flag |= dfs(adj,vis,pathVis,ans,ele);
            if(flag) break;
        }
        
        if(!flag){
            ans.push_back(curr);
            pathVis[curr]=0;
        }


        return flag;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int>vis(n);
        vector<int>pathVis(n);

        vector<int>ans;

        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            dfs(graph,vis,pathVis,ans,i);
        }

        sort(ans.begin(),ans.end());


        return ans;
    }
};
