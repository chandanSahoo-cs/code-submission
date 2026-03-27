class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>>adj(n+1,vector<int>(n+1));

        for(auto ele:trust){
            adj[ele[0]][ele[1]]=1;
        }

        int l = 1;

        for(int i=1;i<=n;i++){
            if(adj[l][i]){
                l=i;
            }
        }

        for(int i=1;i<=n;i++){
            if(i==l) continue;
            if(adj[l][i] || !adj[i][l]) return -1;
        }

        return l;
    }
};
