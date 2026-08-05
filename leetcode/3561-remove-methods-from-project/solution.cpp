class Solution {
public:
    void dfs(vector<vector<int>>&adj, vector<int>&infect, int u){
        if(infect[u]) return;
        infect[u] = 1;

        for(auto v:adj[u]){
            dfs(adj,infect,v);
        }

        return;
    }


    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invo) {
        vector<vector<int>>adj(n); // invokes
        vector<vector<int>>radj(n); // invoked by

        for(auto &ele:invo){
            adj[ele[0]].push_back(ele[1]); 
            radj[ele[1]].push_back(ele[0]);
        }

        vector<int>infect(n);

        dfs(adj,infect,k);

        for(int i=0;i<n;i++){
            if(!infect[i]) continue;

            for(auto v:radj[i]){
                if(!infect[v]){
                    vector<int>ans(n);
                    iota(ans.begin(),ans.end(),0);
                    return ans;
                }
            }
        }

        vector<int>ans;

        for(int i=0;i<n;i++){
            if(!infect[i]) ans.push_back(i);
        }

        return ans;
    }
};
