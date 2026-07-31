class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {

        vector<vector<int>>adj(n);
        vector<int>indegree(n);
        for(auto &ele:p){
            adj[ele[1]].push_back(ele[0]);
            indegree[ele[0]]++;
        }

        queue<int>q;
        int tot = n;

        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                tot--;
            }
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(auto v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                    tot--;
                }
            }
        }


        return tot==0;
    }
};
