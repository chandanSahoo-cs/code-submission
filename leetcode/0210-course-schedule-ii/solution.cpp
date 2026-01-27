class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& preq) {
        vector<vector<int>>adj(n);
        vector<int>indegree(n);

        for(auto ele:preq){
            adj[ele[1]].push_back(ele[0]);

            indegree[ele[0]]++;
        }

        queue<int>q;

        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int>ans;

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(auto ele:adj[curr]){
                indegree[ele]--;

                if(indegree[ele]==0){
                    q.push(ele);
                }
            }

            ans.push_back(curr);
        }

        if(ans.size()<n){
            return {};
        }

        return ans;
    }
};
