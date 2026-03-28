class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>>adj(n);
        vector<int>in(n);

        for(auto &ele:pre){
            adj[ele[1]].push_back(ele[0]);
            in[ele[0]]++;
        }

        queue<int>q;
        vector<int>ans;

        for(int i=0;i<n;i++){
            if(!in[i]){
                q.push(i);
                ans.push_back(i);
            }
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(auto v:adj[u]){
                in[v]--;
                if(!in[v]){
                    q.push(v);
                    ans.push_back(v);
                }
            }
        }

        if(ans.size()<n) return {};

        // reverse(ans.begin(),ans.end());
        return ans;
    }
};

/*
1->2->3->4->5->6
*/
