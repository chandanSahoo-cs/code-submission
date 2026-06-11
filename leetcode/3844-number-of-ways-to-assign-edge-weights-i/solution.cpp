class Solution {
public:
    const int mod = 1e9+7;
    int getHeight(vector<vector<int>>&adj, vector<int>&mark, int u){
        if(mark[u]) return 0;
        mark[u] = 1;

        int mx = 0;

        for(auto v:adj[u]){
            mx = max(mx,getHeight(adj,mark,v));    
        }

        return mx+1;
    }

    int dp[100005][2];

    int rec(int n, int i, int isOdd){
        
        if(i==n) return isOdd;

        if(dp[i][isOdd]!=-1) return dp[i][isOdd];

        int sum = (rec(n,i+1,(isOdd+1)%2)+rec(n,i+1,(isOdd+2)%2))%mod;

        return dp[i][isOdd] = sum;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size()+1;

        vector<vector<int>>adj(n+1);

        for(auto &ele:edges){
            adj[ele[0]].push_back(ele[1]);
            adj[ele[1]].push_back(ele[0]);
        }

        vector<int>mark(n+1);

        int sz = getHeight(adj,mark,1);

        memset(dp,-1,sizeof(dp));

        return rec(sz,1,0);
    }
};
