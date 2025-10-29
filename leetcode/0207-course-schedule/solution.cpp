class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& preq) {
        vector<vector<int>>adj(n);
        vector<int>in(n);

        for(auto ele:preq){
            adj[ele[0]].push_back(ele[1]);
            in[ele[1]]++;
        }

        queue<int>q;

        for(int i=0;i<n;i++){
            if(in[i]==0) q.push(i);
        }

        while(!q.empty()){
            int ele = q.front();
            q.pop();
            for(auto e:adj[ele]){
                in[e]--;
                if(in[e]==0) q.push(e);
            }
        }

        for(auto ele:in){
            if(ele!=0) return false;
        }

        return true;
    }
};
