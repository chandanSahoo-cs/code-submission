#define ll long long
const long long INF = LLONG_MAX;
const int mod = 1e9+7;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<ll,ll>>>adj(n);

        for(auto ele:roads){
            adj[ele[0]].push_back({ele[1],ele[2]});
            adj[ele[1]].push_back({ele[0],ele[2]});
        }

        vector<pair<ll,ll>>vis(n,{INF,0});
        set<pair<ll,ll>>st;

        st.insert({0,0});
        vis[0]={0,1};

        while(!st.empty()){
            auto [cost,u] = *st.begin();
            st.erase(st.begin());

            if(vis[u].first<cost) continue;

            for(auto [v,c]:adj[u]){
                if(vis[v].first>=c+cost){
                    st.erase({vis[v].first,v});
                    if(vis[v].first==c+cost){
                        vis[v].second = (vis[v].second+vis[u].second)%mod;
                        st.insert({c+cost,v});
                    }else{
                        st.insert({c+cost,v});
                        vis[v] = {c+cost,vis[u].second};
                    }
                }
            }
        }
        cout<<vis[n-1].first;
        return vis[n-1].second;
    }
};
