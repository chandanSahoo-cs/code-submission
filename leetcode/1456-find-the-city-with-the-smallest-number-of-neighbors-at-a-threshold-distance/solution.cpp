class Solution {
    const int INF=1e8;
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>adj(n,vector<int>(n,INF));

        for(auto ele:edges){
            adj[ele[0]][ele[1]]=ele[2];
            adj[ele[1]][ele[0]]=ele[2];
        }

        for(int i=0;i<n;i++){
            adj[i][i]=0;
        }

        for(int val=0;val<n;val++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==val || j==val || adj[i][val]==INF || adj[val][j]==INF) continue;
                    int curr = adj[i][val]+adj[val][j];
                    if(adj[i][j]>curr){
                        adj[i][j]=curr;
                    }
                }
            }
        }

        vector<int>cnt(n,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adj[i][j]<=distanceThreshold){
                    cnt[i]++;
                }
            }
        }

        int mn = *min_element(cnt.begin(),cnt.end());

        for(int i=n-1;i>=0;i--){
            if(cnt[i]==mn) return i;
        }

        return -1;
    }
};
