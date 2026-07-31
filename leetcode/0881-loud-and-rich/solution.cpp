class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();

        vector<vector<int>>adj(n);
        vector<int>indegree(n);

        for(auto &ele:richer){
            adj[ele[0]].push_back(ele[1]);
            indegree[ele[1]]++;
        }

        queue<int>q;

        vector<int>ans(n);
        iota(ans.begin(),ans.end(),0);

        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(auto v:adj[u]){
                indegree[v]--;

                if(quiet[ans[v]]>quiet[ans[u]]){
                    ans[v] = ans[u];
                }
                
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }

        return ans;
    }
};
