class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int n = g.size();

        vector<vector<int>>graph(n);

        for(int i=0;i<n;i++){
            for(auto ele:g[i]){
                graph[ele].push_back(i);
            }
        }
        
        vector<int>in(n);
        queue<int>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                in[graph[i][j]]++;
            }
        }

        for(int i=0;i<n;i++){
            if(in[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int ele = q.front();
            q.pop();

            for(auto e:graph[ele]){
                in[e]--;
                if(in[e]==0){
                    q.push(e);
                }
            }
        }

        vector<int>ans;

        for(int i=0;i<n;i++){
            if(in[i]==0) ans.push_back(i);
        }

        return ans;
    }
};
