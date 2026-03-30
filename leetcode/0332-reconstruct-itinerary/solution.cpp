class Solution {
public:
    void dfs(unordered_map<string,set<pair<string,int>>>&adj, vector<int>&vis, string u, vector<string>&res){

        for(auto &[v,ind]:adj[u]){
            if(vis[ind]) continue;
            vis[ind]=1;
            dfs(adj,vis,v,res);
        }
        res.push_back(u);

        return;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,set<pair<string,int>>>adj;

        for(int i=0;i<tickets.size();i++){
            adj[tickets[i][0]].insert({tickets[i][1],i});
        }

        vector<string>res;
        vector<int>vis(tickets.size());

        dfs(adj,vis,"JFK",res);
        reverse(res.begin(),res.end());

        return res;

    }
};
