class Solution {
public:
    bool traverse(vector<vector<pair<int,int>>> &adj, int src, int trg, int m,int k){
        int n = adj.size();
        vector<vector<bool>>vis(n,vector<bool>(k+1));
        queue<pair<int,int>>q;

        q.push({src,k});
        vis[src][k] = 1;

        while(!q.empty()){
            auto [u,remk] = q.front();
            q.pop();

            if(u==trg) return true;

            for(auto &[v,w]:adj[u]){
                int nk = remk-(w>m);
                if(nk>=0 && !vis[v][nk]){
                    q.push({v,nk});
                    vis[v][nk] = 1;
                }
            }
        }

        return false;
    }
    
    int minimumThreshold(int n, vector<vector<int>>& edges, int src, int trg, int k) {
        vector<vector<pair<int,int>>>adj(n);
        int mx = 0;
        
        for(auto &ele:edges){
            adj[ele[0]].push_back({ele[1],ele[2]});
            adj[ele[1]].push_back({ele[0],ele[2]});
            mx = max(mx,ele[2]);
        }

        int l = 0, r = mx;
        int ans = -1;
        
        while(l<=r){
            int m = l+(r-l)/2;
            if(traverse(adj,src,trg,m,k)){
                ans = m;
                r = m-1;
            }else{
                l = m+1;
            }
        }
        return ans;
    }
};
