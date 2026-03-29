class Solution {
public:
    double dfs(unordered_map<string,vector<pair<string,double>>>&adj, unordered_set<string>&vis, string u, string tr){
        if(u==tr) return 1.0;
        if(vis.count(u)) return -1.0;

        vis.insert(u);

        for(auto &[v,val]:adj[u]){
            double hold = dfs(adj,vis,v,tr);
            if(hold!=-1.0){
                return val*hold;
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& values, vector<vector<string>>& q) {
        unordered_map<string,vector<pair<string,double>>>adj;
        int n = eq.size();

        for(int i=0;i<n;i++){
            string u = eq[i][0], v = eq[i][1]; 
            double val = values[i];

            adj[u].push_back({v,val});
            adj[v].push_back({u,1.0/val});
        }

        vector<double>ans;

        for(auto &ele:q){
            unordered_set<string>vis;
            string u = ele[0], v = ele[1];

            if(adj.find(u)==adj.end() || adj.find(v)==adj.end()) ans.push_back(-1.0);
            else ans.push_back(dfs(adj,vis,u,v));
        }

        return ans;
    }
};
