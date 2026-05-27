class Solution {
public:
    int dfs(vector<int>& edges, vector<int>&vis, vector<int>&pathVis, int curr, int prevLen){
        if(pathVis[curr]!=-1) return prevLen-pathVis[curr];
        if(vis[curr]) return -1;

        pathVis[curr] = prevLen;
        vis[curr]=1;

        int v = edges[curr];
        int ans = -1;

        if(v!=-1){
            ans = dfs(edges,vis,pathVis,v,prevLen+1);
        }

        pathVis[curr] = -1;

        return ans;
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();

        vector<int>vis(n,0);
        vector<int>pathVis(n,-1);

        int mx = -1;

        for(int i=0;i<n;i++){
            mx = max(mx,dfs(edges,vis,pathVis,i,0));
        }

        return mx;
    }
};
