class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<int>degree(n);

        for(auto &ele:edges){
            adj[ele[0]].push_back(ele[1]);
            adj[ele[1]].push_back(ele[0]);
            degree[ele[0]]++;
            degree[ele[1]]++;
        }

        queue<int>q;

        for(int i=0;i<n;i++){
            if(degree[i]<=1){
                q.push(i);
            }
        }

        while(!q.empty()){
            int sz = q.size();
            if(n<=2) break;

            for(int i=0;i<sz;i++){
                int u = q.front();
                q.pop();

                for(auto v:adj[u]){
                    if(degree[v]<=1) continue;
                    degree[v]--;
                    n--;
                    if(degree[v]==1){
                        q.push(v);
                    }
                }
            }
        }

        vector<int>ans;

        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};
