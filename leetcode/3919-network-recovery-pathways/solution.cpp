#define ll long long

class Solution {
public:
    bool dijisktra(vector<vector<pair<int,ll>>>&adj, vector<bool>& online, ll k, ll mid){
        int n = online.size();

        vector<ll>dist(n,LLONG_MIN);
        priority_queue<pair<ll,int>>pq;

        pq.push({k,0});
        dist[0] = k;

        while(!pq.empty()){
            auto [nk,u] = pq.top();
            pq.pop();

            if(u==n-1) return true;

            if(nk<dist[u]) continue;

            for(auto &[v,cost]:adj[u]){
                if(cost>=mid && online[v] && nk-cost>=0){
                    if(nk-cost>=dist[v]){
                        dist[v] = nk-cost;
                        pq.push({dist[v],v});
                    }
                }
            }
        }

        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, ll k) {
        int n = online.size();

        vector<vector<pair<int,ll>>>adj(n);

        ll mx = 0;

        for(auto &ele:edges){
            adj[ele[0]].push_back({ele[1],ele[2]});
            mx = max(mx,(ll)ele[2]);
        }

        ll l = 0,r = mx;
        ll ans = -1;

        while(l<=r){
            ll m = l+(r-l)/2;

            if(dijisktra(adj,online,k,m)){
                ans = m;
                l=m+1;
            }else r=m-1;
        }

        return ans;
    }
};
