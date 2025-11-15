class Solution {
    const int INF = 1e8;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);

        for(auto ele:times){
            adj[ele[0]].push_back({ele[1],ele[2]});
        }

        set<vector<int>>st;

        st.insert({0,k});

        vector<int>dist(n+1,INF);
        dist[k]=0;

        while(!st.empty()){
            auto node = *st.begin();
            st.erase(node);

            for(auto &ele:adj[node[1]]){
                int v = ele.first;
                int cost = ele.second;
                if(node[0]+cost<dist[v]){
                    st.erase({dist[v],v});
                    dist[v]=node[0]+cost;
                    st.insert({dist[v],v});
                }
            }
        }

        int mx = *max_element(dist.begin()+1,dist.end());

        if(mx==INF) return -1;
        else return mx;

    }
};
