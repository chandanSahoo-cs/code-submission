class Solution {
public:
    const int INF = 1e9+7;

    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(n);

        for(auto ele:edges){
            adj[ele[0]].push_back({ele[1],ele[2]});
            adj[ele[1]].push_back({ele[0],2*ele[2]});
        }

        vector<int>dist(n,INF);

        set<pair<int,int>>st;
        st.insert({0,0});

        dist[0] = 0;

        while(!st.empty()){
            auto [weigh,node] = *st.begin();
            st.erase(*st.begin());

            if(weigh>dist[node]) continue;

            for(auto [v,w]:adj[node]){
                if(dist[v]>weigh+w){
                    st.erase({dist[v],v});
                    st.insert({weigh+w,v});
                    dist[v] = weigh+w;
                }
            }
        }

        return dist[n-1]==INF?-1:dist[n-1];
    }
};
