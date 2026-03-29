class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>in(n);
        vector<vector<int>>adj(n);


        for(auto &ele:edges){
            adj[ele[0]].push_back(ele[1]);
            in[ele[1]]++;
            
            adj[ele[1]].push_back(ele[0]);
            in[ele[0]]++;
        }

        queue<int>q;

        for(int i=0;i<n;i++){
            if(in[i]<=1) q.push(i);
        }

        while(!q.empty() && n>2){
            int sz = q.size();

            for(int i=0;i<sz;i++){
                int u = q.front();
                q.pop();

                for(auto v:adj[u]){
                    in[v]--;
                    if(in[v]==1){
                        q.push(v);
                    }
                }
                n--;
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
