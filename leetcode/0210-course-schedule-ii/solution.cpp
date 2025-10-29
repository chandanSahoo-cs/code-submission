class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& preq) {
        vector<vector<int>>adj(n);
        vector<int>in(n);

        for(auto ele:preq){
            adj[ele[1]].push_back(ele[0]);
            in[ele[0]]++;
        }

        queue<int>q;

        vector<int>ans;

        for(int i=0;i<n;i++){
            if(in[i]==0){
                q.push(i);
                ans.push_back(i);
            }
        }

        while(!q.empty()){
            int ele = q.front();
            q.pop();

            for(auto e:adj[ele]){
                in[e]--;
                if(in[e]==0){
                    q.push(e);
                    ans.push_back(e);
                }
            }
        }

        return ans.size()==n ? ans: decltype(ans)();
    }
};
