const int INF = 1e9;
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<vector<int>>adj(n,vector<int>(n,INF));
        
        for(int i=0;i<n;i++){
            adj[i][i]=1;
        }

        for(auto &ele:pre){
            adj[ele[0]][ele[1]]=1;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(adj[i][k]==INF || adj[k][j]==INF) continue;
                    adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
        }

        vector<bool>ans;

        for(auto &ele:queries){
            if(adj[ele[0]][ele[1]]<INF) ans.push_back(true);
            else ans.push_back(false);
        }

        return ans;
    }
};
