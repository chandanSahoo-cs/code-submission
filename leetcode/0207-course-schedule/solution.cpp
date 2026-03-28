class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>in(n);
        vector<vector<int>>adj(n);

        for(auto ele:pre){
            adj[ele[1]].push_back(ele[0]);
            in[ele[0]]++;
        }

        queue<int>q;

        for(int i=0;i<n;i++){
            if(!in[i]) q.push(i);
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(auto v:adj[u]){
                in[v]--;
                if(in[v]==0){
                    q.push(v);
                }
            }
        }

        for(int i=0;i<n;i++){
            if(in[i]) return false;
        }

        return true;
    }
};
