#define ll long long
class Solution {
public:
    const int mod = 1e9+7;
    const int LOG = 18;

    void dfs(vector<vector<int>>&adj, vector<int>&depth, vector<vector<int>>&up, int u, int parent){
        up[u][0] = parent;

        for (int j = 1; j < LOG; j++) {
            if (up[u][j - 1])
                up[u][j] = up[up[u][j - 1]][j - 1];
        }

        for (int v : adj[u]) {
            if(v==parent) continue;
            depth[v] = depth[u] + 1;
            dfs(adj,depth,up,v, u);
        }
    }

    int lift(vector<vector<int>>&up, int u, int k) {
        for (int j = 0; j < LOG; j++) {
            if (k & (1 << j))
                u = up[u][j];
        }
        return u;
    }

    int calcLCA(vector<int>&depth, vector<vector<int>>& up, int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        u = lift(up,u, depth[u] - depth[v]);

        if (u == v)
            return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

    ll binExp(ll base, ll exp){

        ll ans = 1;

        while(exp){
            if(exp&1){
                ans = (ans*base)%mod;
            }
            base = (base*base)%mod;
            exp>>=1;
        }
        return ans;
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size()+1;
        vector<vector<int>>adj(n+1);

        for(auto &ele:edges){
            adj[ele[0]].push_back(ele[1]);
            adj[ele[1]].push_back(ele[0]);
        }

        vector<int>depth(n+1);
        vector<vector<int>>up(n+1,vector<int>(LOG,0));


        dfs(adj,depth,up,1,0);
        vector<int>ans;


        for(auto &ele:queries){
            int u = ele[0], v = ele[1];

            if(u==v){
                ans.push_back(0);
                continue;
            }

            int lca = calcLCA(depth,up,u,v);

            int dist = depth[u]+depth[v]-2*depth[lca];
            ans.push_back(binExp(2,dist-1));
        }

        return ans;
    }
};
