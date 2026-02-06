class Solution {
public:

    int longestCycle(vector<int>& edges) {
        int n = edges.size();

        vector<int>vis(n);

        int mx = -1;

        for(int i=0;i<n;i++){
            if(vis[i] || edges[i]==-1) continue;

            unordered_map<int,int>pathVis;

            int node = i;
            int curr = 1;

            while(node!=-1 && !vis[node]){
                vis[node]=1;
                pathVis[node] = curr++;

                int ele = edges[node];

                if(ele!=-1 && pathVis.find(ele)!=pathVis.end()){
                    mx = max(mx,curr-pathVis[ele]);
                    break;
                }else{
                    node = ele;
                }
            }
        }

        return mx;
    }
};
